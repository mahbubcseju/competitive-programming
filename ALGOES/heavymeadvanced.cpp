/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include<bits/stdc++.h>
#include<string.h>
#include<stdio.h>
#define ll long long int
#define ull unsigned long long int
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PI(a) printf("%d",a)
#define PL(a) printf("%lld",a)
#define PT(t) printf("Case %d: ",t)
#define PB push_back
#define x first
#define y second
#define xx first.first
#define xy first.second
#define yx second.first
#define yy second.second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())-1
#define f(i,a,b) for(int i=a;i<=b; i++)
#define fr(i,a,b) for(int i=a;i<=b; i++)
#define frr(i,a,b) for(int i=a;i>=b; i--)
#define frv(i,a)  for(int i=0;i<a.size();i++)
#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define Endl "\n"
#define mk make_pair
using namespace std;
template <class T> inline T BM(T p, T e, T M) {
    ll ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M) {
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e) {
    ll ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
template <class T>string NTS ( T Number ) {
    stringstream ss;
    ss << Number;
    return ss.str();
}
template <class T>T stringtonumber ( const string &Text ) {
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
template <class T>bool ISLEFT ( T a, T b, T c) {
    if (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define MX 50009ll
#define md 1000000007ll
#define md1 1000000007ll
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29

typedef pair<int,int>P;
//////////////////////////
/////////////////////////
vector<int> adj[MX];
int chainNo,ptr;
int par[MX],lev[MX];
int subTree[MX];
int Start[MX],chainID[MX];//Needs to clear
int pos[MX];
int cvr[MX][2];
int tr[4*MX];
void init() {
    SET(Start);
    SET(chainID);
    chainNo=0,ptr=0;
}
void dfs(int u,int p,int l) {
    par[u] = p;
    lev[u] = l;
    subTree[u] = 1;

    for (int i=0; i<adj[u].size(); i++) {
        int v= adj[u][i];

        if (v == p)     continue;

        dfs(v,u,l+1);
        subTree[u] += subTree[v];
    }
}

void hld(int u,int p) {
    if (Start[chainNo] == 0)
        Start[chainNo] = u;

    chainID[u] = chainNo;
    pos[u] = ++ptr;
    cvr[u][0] = ptr;
    int sc = -1, mx = -1;

    for (int i=0; i<adj[u].size(); i++) {
        int v = adj[u][i];

        if ( v!= p && subTree[v] > mx) {
            sc = i;
            mx = subTree[v];
        }
    }

    if (sc != -1 )      hld(adj[u][sc],u);

    for (int i=0; i<adj[u].size(); i++) {
        if (i == sc)        continue;

        int v= adj[u][i];

        if (v!=p) {
            chainNo++;
            hld(v,u);
        }
    }
    cvr[u][1] = ptr;
}
int ar[MX+2];
void up(int no,int s,int e,int in,int val) {
    if(s==e) {
        tr[no]=val;
        return ;
    }
    int mid=(s+e)>>1;
    if(mid>=in)up(no*2,s,mid,in,val);
    else up(no*2+1,mid+1,e,in,val);
    tr[no]=gcd(tr[no*2],tr[no*2+1]);
}


int qu(int no,int s,int e,int st,int en) {
    if(s>=st&&e<=en)
        return tr[no];
    int mid=(s+e)>>1;
    if(mid>=en)return qu(no*2,s,mid,st,en);
    else if(mid<st)return qu(no*2+1,mid+1,e,st,en);
    else return gcd(qu(no*2,s,mid,st,mid),qu(no*2+1,mid+1,e,mid+1,en));
}

int lca(int u,int v) {
    while(chainID[u]!=chainID[v])
        if(lev[Start[chainID[u]]]>lev[Start[chainID[v]]])
            u=par[Start[chainID[u]]];
        else v=par[Start[chainID[v]]];

    return lev[u]<lev[v]?u:v;
}

P range[MX+2];
int n;
int qufromutov(int u,int v) {

    int lc=lca(u,v);
    int ss=0;
    while(chainID[u]!=chainID[lc]) {
        int h=Start[chainID[u]];
        range[++ss]=mk(u,h);
        u=par[h];
    }
    range[++ss]=mk(u,lc);
    while(chainID[v]!=chainID[lc]) {
        int h=Start[chainID[v]];
        range[++ss]=mk(v,h);
        v=par[h];
    }
    range[++ss]=mk(v,lc);
    int ans=qu(1,1,n,pos[range[1].y],pos[range[1].x]);
    for(int i=1; i<=ss; i++) {
        ans=gcd(ans,qu(1,1,n,pos[range[i].y],pos[range[i].x]));
    }
    return ans;
}

int main() {


    while(I(n)!=EOF) {
        init();
        for(int i=1; i<=n; i++)I(ar[i]);

        for(int i=1; i<n; i++) {
            int x,y;
            I2(x,y);
            x++;
            y++;
            adj[x].PB(y);
            adj[y].PB(x);
        }
        dfs(1,-1,0);
        hld(1,-1);

        for(int i=1; i<=n; i++) {
            up(1,1,n,pos[i],ar[i]);
            adj[i].clear();
        }

        int q;
        I(q);
        while(q--) {
            int t,x,y;
            I3(t,x,y);
            if(t==1) {
                x++,y++;
                int ans=qufromutov(x,y);
                PI(ans),NL;

            } else {
                ++x;
                up(1,1,n,pos[x],y);
            }
        }

    }

    return 0;
}
