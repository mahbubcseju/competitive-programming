#include<cfloat>
#include<climits>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<string.h>
#define I(a) scanf("%d",&a)
#define xx first
#define yy second
using namespace std;
const int N=10000;
int par[N+3];//Parent of every node
int heavy[N+3];// heavy node of every node that means kon child er weight beshi
int dep[N+3];//level of node
int siz[N+3];//Number of node in its subtree
int chain[N+3];//ith element ta Koto number chain that means chain number
int head[N+3];//Head of that element se jei chain a ache tar head
int q[N+3],*qb,*qf;
int ar[N+3];//For segment tree  inorder traverse er por node gola 1 index a thake
int elpos[N+3]; //kon element er pos koto
vector<pair<int,int> >a[N+3];
int n;

void BFS() {
    qf=qb=q;
    par[1]=0;
    dep[1]=1;
    *qb++=1;
    while(qf<qb) {
        for(int i=*qf++,k=0; k<a[i].size(); k++) {
            int j=a[i][k].first;
            if(par[i]!=j) {
                par[j]=i;
                dep[j]=dep[i]+1;
                *qb++=j;
            }
        }
    }
    memset(siz,0,sizeof siz);
    memset(heavy,-1,sizeof heavy);
    for(int k=n-1; k>=0; k--) {
        int j=q[k];
        int i=par[j];
        siz[j]++;
        siz[i]+=siz[j];
        if(heavy[i]==-1||siz[j]>siz[heavy[i]])heavy[i]=j;

    }
    int c=0;
    int sz=0;
    for(int i=1; i<=n; i++) {
        if(par[i]==0||heavy[par[i]]!=i) {
            ++c;
            for(int k=i; k!=-1; k=heavy[k]) {
                chain[k]=c;
                head[k]=i;
                ar[++sz]=k;
                elpos[k]=sz;
            }

        }
    }


}
int lca_1(int i, int j) {
    while (chain[i] != chain[j])
        if (dep[head[i]] > dep[head[j]])
            i = par[head[i]];
        else
            j = par[head[j]];

    return dep[i] < dep[j] ? i : j;
}

int val[N+2];
int arr[N*4];
void init() {
    for(int i=0; i<=n; i++)a[i].clear(),val[i]=0;
    memset(arr,0,sizeof arr);
    memset(val,0,sizeof val);
    memset(q,0,sizeof q);
    memset(dep,0,sizeof dep);
    memset(heavy,0,sizeof heavy);
    memset(chain,0,sizeof chain);
    memset(head,0,sizeof head);

}
void build(int no,int i,int j) {
    if(i==j) {
        arr[no]=val[i];
        return;
    }
    int mid=(i+j)/2;
    build(no*2,i,mid);
    build(no*2+1,mid+1,j);
    arr[no]=max(arr[no*2],arr[no*2+1]);

}
int query(int no,int i,int j,int s,int e) {

    //cout<<no<<" "<<i<<" "<<j<<" "<<s<<" "<<e<<endl;
    if(i>=s&&j<=e) {

        return arr[no];
    }
//    if(co==50)
//    return 1;
    int mid=(i+j)/2;
    if(mid>=e)return query(no*2,i,mid,s,e);
    else if(mid<s)return query(no*2+1,mid+1,j,s,e);
    else return max(query(no*2,i,mid,s,mid),query(no*2+1,mid+1,j,mid+1,e));
}
void update(int no,int s,int e,int in) {
    if(s==in&&e==in) {
        arr[no]=val[in];
        return;
    }
    int mid=(s+e)/2;
    if(mid>=in)update(no*2,s,mid,in);
    else update(no*2+1,mid+1,e,in);
    arr[no]=max(arr[no*2],arr[no*2+1]);

}
int red(int x,int y) {
    int ans=-10000000;

    if(x!=y) {
        while(chain[x]!=chain[y]) {
            if(dep[x]>dep[y])swap(x,y);
            ans=max(ans,query(1,1,n,elpos[head[y]],elpos[y]));
            y=par[head[y]];
        }
        if(x!=y) {
            if(dep[x]>dep[y])swap(x,y);
            // cout<<"lol"<<endl;
            // cout<<elpos[x]<<" "<<elpos[y]<<endl;
            ans=max(ans,query(1,1,n,elpos[x]+1,elpos[y]));
        }
    }
    return ans;
}

int main() {

    int tc;
    I(tc);
    while(tc--) {

        I(n);
        pair<pair<int,int> ,int >ind[n+2];
        for(int i=1; i<n; i++) {
            int x,y,z;
            I(x);
            I(y);
            I(z);
            ind[i]=make_pair(make_pair(x,y),z);
            a[x].push_back(make_pair(y,z));
            a[y].push_back(make_pair(x,z));

        }

        BFS();
        for(int i=1; i<n; i++) {
            if(par[ind[i].xx.yy]!=ind[i].xx.xx) {
                swap(ind[i].xx.xx,ind[i].xx.yy);
            }
            val[elpos[ind[i].xx.yy]]=ind[i].yy;
        }
        build(1,1,n);
        while(1) {
            char ch[10];
            scanf("%s",&ch);
            if(!strcmp(ch,"DONE"))break;
            else if(!strcmp(ch,"QUERY")) {
                int x,y;
                I(x);
                I(y);
                int u=lca_1(x,y);
                int ans=max(red(u,x),red(u,y));
                printf("%d\n",ans);
            } else {
                int x,y;
                I(x);
                I(y);
                ind[x].yy=y;
                val[elpos[ind[x].xx.yy]]=y;
                update(1,1,n,elpos[ind[x].xx.yy]);
            }
        }
        init();
    }

    return 0;
}
