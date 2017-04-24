
//https://www.codechef.com/SNCKPA16/problems/SUBSEG2
#include<bits/stdc++.h>
using namespace std;
#define mx1 400000
#define x first
#define y second
#define mx 1000000
typedef pair<int,int>P;
int mp[mx+2];
int mp1[mx+2];
bool cmp(P x,P y) {
    if(x.y==y.y) {
        return x.x>y.x;
    } else return x.y<y.y;
}
struct data {
    int info;
    int l,r;
    data() {
        info=0;
        l=0;
        r=0;
    }
};
data tr[mx1*20];
int avail;
int  update(int pre,int nw,int s,int e,int val) {

    if(s==e) {
        tr[nw].info++;
        return nw;
    }
    int mid=(s+e)/2;
    if(val<=mid) {
        ++avail;
        tr[nw].l=update(tr[pre].l,avail,s,mid,val);
        tr[nw].r=tr[pre].r;
    } else {
        avail++;
        tr[nw].l=tr[pre].l;
        tr[nw].r=update(tr[pre].r,avail,mid+1,e,val);
    }
    tr[nw].info=tr[tr[nw].l].info+tr[tr[nw].r].info;
    return nw;

}
int query(int nw,int s,int e,int st,int en) {
    if(nw==0)return 0;
    if(s>=st&&e<=en) {
        return tr[nw].info;
    }
    int mid=(s+e)/2;
    if(mid>=en)return query(tr[nw].l,s,mid,st,en);
    else if(mid<st)return query(tr[nw].r,mid+1,e,st,en);
    else {
        return query(tr[nw].l,s,mid,st,mid)+query(tr[nw].r,mid+1,e,mid+1,en);

    }

}
int main() {

    int n,m;
    cin>>n>>m;
    P a[n+2];

    int sz=0;
    for(int i=1; i<=n; i++) {
        int x,y;
        cin>>a[i].x>>a[i].y;
        mp[a[i].x]++;
        mp[a[i].y]++;
    }
    P b[m+2];
    for(int i=1; i<=m; i++) {
        int x,y;
        cin>>b[i].x>>b[i].y;
        mp[b[i].x]++;
        mp[b[i].y]++;
    }
    for(int i=1; i<=mx; i++) {
        if(mp[i]) {
            mp1[i]=++sz;
        }
    }
    memset(mp,0,sizeof mp);
    sort(a+1,a+n+1,cmp);
    for(int i=1; i<=n; i++) {
        mp[mp1[a[i].y]]=max(mp[mp1[a[i].y]],mp1[a[i].x]);
    }

    int root[sz+2];
    memset(root,0,sizeof root);
    root[0]=0;
    for(int i=1; i<=sz; i++) {
        if(mp[i]==0) {
            root[i]=++avail;
            tr[avail]=tr[root[i-1]];
        } else {
            int l=mp[i];
             int x=query(root[i-1],1,sz,l+1,sz);
            if(x) {
                root[i]=++avail;
                tr[avail]=tr[root[i-1]];
            } else {
                ++avail;
                root[i]=update(root[l-1],avail,1,sz,l);
            }
        }
    }
    for(int i=1; i<=m; i++) {
        int x=query(root[mp1[b[i].y]],1,sz,1,mp1[b[i].y]);
        if(mp1[b[i].x]-1>=1)
            x-=query(root[mp1[b[i].y]],1,sz,1,mp1[b[i].x]-1);
        cout<<x<<endl;
    }


    return 0;
}
