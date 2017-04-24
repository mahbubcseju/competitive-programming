
//http://codeforces.com/problemset/problem/669/E
#include<bits/stdc++.h>
using namespace std;
#define md 1e9+7
struct data {
    int info;
    int l,r;
    data() {
        info=0;
        l=0;
        r=0;
    }
};
data tr[100000*40];
int avail=0;
int update(int no,int s,int e,int in,int val) {
    int idx=no;
    if(!no) {
        idx=++avail;
        tr[idx]=data();
    }
    if(s==e) {
        tr[idx].info+=val;
        return idx;
    }
    int mid=(s+e)/2;
    if(mid>=in) {
        tr[idx].l=update(tr[idx].l,s,mid,in,val);
    } else {
        tr[idx].r =update(tr[idx].r,mid+1,e,in,val);
    }
    tr[idx].info=(tr[tr[idx].l].info+tr[tr[idx].r].info);
    return idx;


}
int query(int idx,int s,int e,int st,int en) {
    if(idx==0)return 0;
    if(s>=st&&e<=en)return tr[idx].info;
    int mid=(s+e)/2;
    if(mid>=en)return query(tr[idx].l,s,mid,st,en);
    else if(mid<st)
        return query(tr[idx].r,mid+1,e,st,en);
    else return query(tr[idx].l,s,mid,st,mid)+query(tr[idx].r,mid+1,e,mid+1,en);

}
int main() {

    int n;
    cin>>n;
    map<int,int>mp;
    while(n--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(x==1){
            mp[z]=update(mp[z],1,md,y,1);
        }
        else if(x==2){
            mp[z]=update(mp[z],1,md,y,-1);

        }
        else
        {
            printf("%d\n",query(mp[z],1,md,1,y));
        }
    }

    return 0;
}


