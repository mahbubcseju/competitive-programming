/*You are given a tree with N nodes.The tree nodes are numbered from 1 to N.Each node has an integer weight.

We will ask you to perform the following operation:

u v k : ask for the kth minimum weight on the path from node u to node v
*/

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
#define ll long long int
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define PI(a) printf("%d\n",a)
#define PB push_back
#define xx first
#define yy second
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define mk make_pair
using namespace std;
#define mx  100000
#define md 1000000007
#define maxp 1000004
typedef pair<int , int >P;
typedef vector<int >V;
////////define value/////
struct node
{
    int cnt;
    node *l,*r;
    node()
    {
        cnt=0;
        l=r=NULL;
    }
};
node * chL(node *p)
{
    return (p==NULL?NULL:p->l);
}
node *chR(node *p)
{
    return (p==NULL?NULL:p->r);
}
P a[mx+4];
int pr[mx+4];
int val[mx+4];
int lev[mx+4];
vector<int>v[mx+4];
node tree[mx*20+4];
node *root[mx+4];
int avail;
int vis[mx+4];
int tab[22][mx+4];
void sptab()
{
    for(int i=1; i<=20; i++)
    {
        for(int j=1; j<=mx; j++)
        {
            if(tab[i-1][j]!=-1)
            {
                tab[i][j]=tab[i-1][tab[i-1][j]];
            }
        }
    }

}
int lca(int x,int y)
{
    if(lev[x]>lev[y])swap(x,y);
    for(int i=20; i>=0; i--)
    {
        if(tab[i][y]!=-1&&lev[tab[i][y]]>=lev[x])y=tab[i][y];
    }
    if(x==y)return y;
    for(int i=20; i>=0; i--)
    {
        if(tab[i][x]!=tab[i][y])
        {
            x=tab[i][x];
            y=tab[i][y];
        }
    }
    return tab[0][x];
}
node *update(node *pre,int l,int r,int val)
{
    node *u=&tree[++avail];
    if(pre!=NULL)*u=*pre;
    u->cnt++;
    if(l==r)
    {
        return u;
    }
    int mid=(l+r)/2;
    if(val<=mid)u->l=update(u->l,l,mid,val);
    else u->r=update(u->r,mid+1,r,val);
    return u;

}
int query(node *lel,node *ler,node *ril,node *rir,int l,int r,int pos)
{
    if(l==r)
    {
        return l;
    }
    int mid=(l+r)/2;
    int sum=0;
    if(ler!=NULL&&ler->l!=NULL)sum+=ler->l->cnt;
    if(rir!=NULL&&rir->l!=NULL)sum+=rir->l->cnt;
    if(lel!=NULL&&lel->l!=NULL)sum-=lel->l->cnt;
    if(ril!=NULL&&ril->l!=NULL)sum-=ril->l->cnt;
    if(pos<=sum)
        query(chL(lel),chL(ler),chL(ril),chL(rir),l,mid,pos);
    else return
            query(chR(lel),chR(ler),chR(ril),chR(rir),mid+1,r,pos-sum);
}

int main()
{
    int n,m;
    I2(n,m);
    for(int i=1; i<=n; i++)
    {
        I(a[i].xx);
        a[i].yy=i;
    }

    sort(a+1,a+n+1);
    pr[a[1].yy]=1;
    val[1]=a[1].xx;
    for(int i=2; i<=n; i++)
    {
        if(a[i].xx==a[i-1].xx)
        {
            pr[a[i].yy]=pr[a[i-1].yy];
        }
        else
        {
            pr[a[i].yy]=i;

            val[i]=a[i].xx;
        }
    }
    for(int i=1; i<=n-1; i++)
    {
        int x,y;
        I2(x,y);
        v[x].PB(y);
        v[y].PB(x);
    }
    SETR(vis);
    SETR(tab);
    vis[1]=0;
    root[0]=NULL;
    queue<int>q;
    lev[1]=1;
    tab[0][1]=-1;
    q.push(1);
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        root[f]=update(root[vis[f]],1,n,pr[f]);
        for(int i=0; i<v[f].size(); i++)
        {
            int u=v[f][i];
            if(vis[u]==-1)
            {
                vis[u]=f;
                lev[u]=lev[f]+1;
                tab[0][u]=f;
                q.push(u);
            }
        }
    }
    sptab();
    for(int i=1; i<=m; i++)
    {
        int x,y,z;
        I3(x,y,z);
        int lc=lca(x,y);
        int r;
        //cout<< vis[lc]<<endl;
        r=query(root[vis[lc]],root[x],root[lc],root[y],1,n,z);
        r=val[r];
        PI(r);
    }
    return 0;
}
