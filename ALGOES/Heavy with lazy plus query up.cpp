/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <deque>
#include <climits>
#include <complex>
#include <bitset>
#include <limits>
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
//#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define Endl "\n"
#define mk make_pair
using namespace std;
template <class T> inline T BM(T p, T e, T M)
{
    ll ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b)
{
    if(a<0)a*=-1;
    if(b<0)b*=-1;
    while(a)
    {
        int r=b;
        b=a;
        a=r%a;
    }
    return b;
}
template <class T> inline T mdINV(T a, T M)
{
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e)
{
    ll ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
template <class T>string NTS ( T Number )
{
    stringstream ss;
    ss << Number;
    return ss.str();
}
template <class T>T stringtonumber ( const string &Text )
{
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
template <class T>bool ISLEFT ( T a, T b, T c)
{
    if (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define MX 50002ll
#define md 1000000007
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29

typedef pair<int , int > P;
typedef vector<int> V;
//////////////////////////
/////////////////////////

vector<int> adj[MX];
int chainNo,ptr;
int T[MX],L[MX];
int subTree[MX];
int Start[MX],chainID[MX];//Needs to clear
int pos[MX];
int cvr[MX][2];
inline void Dfs(int u,int p,int l)
{
    T[u] = p;
    L[u] = l;
    subTree[u] = 1;
    for (int i=0; i<adj[u].size(); i++)
    {
        int v= adj[u][i];

        if (v == p)     continue;

        Dfs(v,u,l+1);
        subTree[u] += subTree[v];
    }
}
inline void HLD(int u,int p)
{
    if (Start[chainNo] == 0)
        Start[chainNo] = u;
    chainID[u] = chainNo;
    pos[u] = ++ptr;
    cvr[u][0] = ptr;
    int sc = -1, mx = -1;
    int sis=adj[u].size();
    for (int i=0; i<sis; i++)
    {
        int v = adj[u][i];

        if ( v!= p && subTree[v] > mx)
        {
            sc = i;
            mx = subTree[v];
        }
    }
    if (sc != -1 )      HLD(adj[u][sc],u);
    for (int i=0; i<sis; i++)
    {
        if (i == sc)        continue;
        int v= adj[u][i];
        if (v!=p)
        {
            chainNo++;
            HLD(v,u);
        }
    }

    cvr[u][1] = ptr;
}
int n;
//int tab[MX+2][20],n;
//void sparse()
//{
//    SETR(tab);
//    for(int i=1; i<=n; i++)tab[i][0]=T[i];
//
//    for(int i=1; i<=17; i++)
//    {
//        for(int j=1; j<=n; j++)
//        {
//            if(tab[j][i-1]!=-1)
//            {
//                tab[j][i]=tab[tab[j][i-1]][i-1];
//            }
//        }
//    }
//}
inline int lca(int x,int y)
{

////lol;
//    if(L[x]<L[y])swap(x,y);
//
//    for(int i=17; i>=0; i--)
//    {
//        if(tab[x][i]!=-1&&L[tab[x][i]]>=L[y])x=tab[x][i];
//    }
//    if(x==y)return x;
//
//    for(int i=17; i>=0; i--)
//    {
//        if(tab[x][i]!=-1&&tab[x][i]!=tab[y][i])
//            x=tab[x][i],y=tab[y][i];
//    }
//    //  lol;
//    return T[x];
    while(chainID[x]!=chainID[y])
    {
        if(L[Start[chainID[x]]]>L[Start[chainID[y]]])
        {
            x=T[Start[chainID[x]]];
        }
        else y=T[Start[chainID[y]]];
    }
    return L[x]<L[y]?x:y;
}

struct nd
{
    int fi,la;
    int difgcd;
} tree[MX*4];
int lazy[MX*4];

int val[MX+2];

inline void build(int node,int ss,int se)
{
    if(ss == se)
    {
        tree[node].fi = tree[node].la = val[ss];
        tree[node].difgcd = 0;
        return;
    }
    int p = (node<<1);
    int q = p|1;
    int mid = (ss+se)>>1;
    build(p,ss,mid);
    build(q,mid+1,se);
    tree[node].fi = tree[p].fi;
    tree[node].la = tree[q].la;
    tree[node].difgcd = __gcd(__gcd(abs(tree[q].fi-tree[p].la),tree[p].difgcd),tree[q].difgcd);

}
inline void relax(int node,int ss,int se)
{
    int k = lazy[node];
    if(k)
    {
        tree[node].fi += lazy[node];
        tree[node].la += lazy[node];
        if(ss^se)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
inline void update(int node,int ss,int se,int qs,int qe,int d)
{
    relax(node,ss,se);
    if(ss > qe || se < qs || ss > se || qs > qe) return;
    if(ss >= qs && se <= qe)
    {
        lazy[node] += d;
        relax(node,ss,se);
        return;
    }
    int p = (node<<1);
    int q = p|1;
    int mid = (ss+se)>>1;
    update(p,ss,mid,qs,qe,d);
    update(q,mid+1,se,qs,qe,d);
    tree[node].fi = tree[p].fi;
    tree[node].la = tree[q].la;
    tree[node].difgcd = __gcd(__gcd(abs(tree[q].fi-tree[p].la),tree[p].difgcd),tree[q].difgcd);
}


inline int query(int node,int ss,int se,int qs,int qe)
{
    if(ss > qe || se < qs || ss > se || qs > qe) return 0;
    relax(node,ss,se);
    if(ss >= qs && se <= qe)
    {
        return __gcd(tree[node].fi,tree[node].difgcd);
    }
    int p = (node<<1);
    int q = p|1;
    int mid = (ss+se)>>1;
    int pp = query(p,ss,mid,qs,qe);
    int qq = query(q,mid+1,se,qs,qe);
    return __gcd(pp,qq);
}
P ar[MX+2];

inline void updateup(int x,int y,int upval)
{
    int sz=0;
    while(1)
    {
        if(chainID[x]==chainID[y])break;
        int x1=Start[chainID[x]];
        ar[++sz]=mk(pos[x1],pos[x]);
        x=T[x1];
    }
    if(pos[y]!=pos[x])
        ar[++sz]=mk(pos[y]+1,pos[x]);
    for(int i=1; i<=sz; i++)update(1,1,n,ar[i].x,ar[i].y,upval);
}


inline int  queryup(int x,int y)
{
    int sz=0;
    while(1)
    {
        if(chainID[x]==chainID[y])break;
        int x1=Start[chainID[x]];
        ar[++sz]=mk(pos[x1],pos[x]);
        x=T[x1];
    }

    ar[++sz]=mk(pos[y],pos[x]);
    int ans=0;
    for(int i=1; i<=sz; i++)ans=__gcd(ans,query(1,1,n,ar[i].x,ar[i].y));
    return ans;
}

int main()
{

    I(n);


    for(int i=1; i<n; i++)
    {
        int u,v,c;
        I2(u,v);
        u++;
        v++;
        adj[u].PB(v);
        adj[v].PB(u);
    }


    chainNo=1;
    ptr=0;
    Dfs(1,-1,1);
    HLD(1,-1);
    //sparse();
    // lol;
    for(int i=1; i<=n; i++)I(val[pos[i]]);
        build(1,1,n);
    int q;
    I(q);
    //  lol;

    while(q--)
    {
        char ch[2];
        int x,y,c;
        SC("%s",ch);
        if(ch[0]=='C')
        {
            I3(x,y,c);
            x++;
            y++;
            int lc=lca(x,y);
            updateup(x,lc,c);
            updateup(y,lc,c);
            update(1,1,n,pos[lc],pos[lc],c);
        }
        else
        {
            int x,y;
            I2(x,y);
            x++,y++;
            int lc=lca(x,y);
            int gc=queryup(x,lc);
            gc=__gcd(gc,queryup(y,lc));
            PI(gc);
            NL;

        }
    }

    return 0;
}
