#include<bits/stdc++.h>
#define S scanf
#define P printf

#define  F(i,a,b) for(int i=a;i<b; i++)
#define FF(i,a,b) for(i=a;i<=b;i++)
#define FI(i,a,b) for((typeof(b)) i=a;i<=b;i++)
#define FR(i, a, b,inc) for(  i = (a); i <= (b); i+=inc )
#define RFR(i, a, b,dec) for(  i = (a); i >= (b); i-=dec )
#define FS(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define PR(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) cout << *it << " "; cout << endl;

#define LL long long int
#define ULL unsigned long long int
#define D double

#define Max(a,b)    (a>b?a:b)
#define Min(a,b)    (a<b?a:b)
#define _Max(a,b,c) Max(a,Max(b,c))
#define _Min(a,b,c) Min(a,Min(b,c))
#define SQR(n)      (n*n)
#define PI          2.0*acos(0.0)

#define all(a) a.begin(),a.end()
#define X  first
#define Y  second
#define MP make_pair

#define PCC        cout<<"Case "<<cas++<<": ";
#define PC         printf("Case %d:",cas++);
#define PCN        printf("Case %d:\n",cas++);
#define NL         printf("\n");
#define cp         printf("here\n");

#define open       freopen("input.txt","r",stdin)
#define close      freopen ("output.txt","w",stdout)
#define Case(a)    printf("Case %d:",a)
#define caseh(a)   printf("Case #%d: ",a)
#define S1(a)      scanf("%d",&a)
#define S2(a,b)    scanf("%d%d",&a,&b)
#define S3(a,b,c)  scanf("%d%d%d",&a,&b,&c)
#define SL1(a)     scanf("%lld",&a)
#define SL2(a,b)   scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define CHR        getchar()
#define PB(x)      push_back(x)
#define pb         push_back
#define PP         pop_back()
#define PF(x)      push_front(x)
#define PPF(x)     pop_front()
#define PS(x)      push(x)
#define sz()       size()
#define UB         upper_bound
#define LB         lower_bound
#define mxe(a,n)   (*max_element(a,a+n))
#define mne(a,n)   (*min_element(a,a+n))
#define SUM(a,n)   (accumulate(a,a+n,0))
#define countbit(x) __builtin_popcount(x)
#define DBG(n)      P("Done %d\n",n);

// I/O
#define I(X)                       scanf("%d", &(X))
#define II(X, Y)                   scanf("%d%d", &(X), &(Y))
#define III(X, Y, Z)               scanf("%d%d%d", &(X), &(Y), &(Z))
#define DI(X) int (X);             scanf("%d", &X)
#define DII(X, Y) int X, Y;        scanf("%d%d", &X, &Y)
#define DIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)

#define ILL(X)          scanf("%lld", &(X))
#define DILL(X) LL (X); scanf("%lld", &X)

// LOOP
#define repv(i,a) for(int i=0;i<(int)a.size();i++)
#define revv(i,a) for(int i=((int)a.size())-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)

#define FS(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define PR(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;

#define MEM(a,val) memset(a,val,sizeof(a));
#define SET(a)     memset(a,-1,sizeof a)
#define CLR(a)     memset(a,0,sizeof a)


using namespace std;

#define VI  vector< int >
#define VII vector< VI >
#define VLL vector< LL >
#define PII pair< int , int >
#define PLL pair< LL , LL >
#define VPI vector< PII >

///         0123456789
#define MX  500007
#define MOD 1000000007
#define INF (1<<30)-1+(1<<30)
#define eps 1e-9

#define base ((1<<l)-1)
#define lft (idx<<1)
#define rgt (lft|1)
#define mid ((l+r)>>1)

/// Hashing Bases & MOD
///           0123456789
#define Base1 10000019ULL
#define Base2 10000079ULL
#define Base3 10000103ULL
#define MOD1  1000000007ULL
#define MOD2  1000000009ULL
#define MOD3  1000000021ULL

VI adj[MX];
int chainNo,ptr;
int T[MX],L[MX];
int subTree[MX];
int Start[MX],chainID[MX];//Needs to clear
int pos[MX];
int cvr[MX][2];
int Tree[4*MX];

void Build(int idx,int l,int r)
{
    if (l == r)
    {
        Tree[idx] = 2;
        return;
    }

    Build(lft,l,mid);
    Build(rgt,mid+1,r);
}

void Update(int idx,int l,int r,int s,int e,int v)
{
    if (l == s && r == e)
    {
        Tree[idx] = v;
        return ;
    }

    if (Tree[idx])
    {
        Tree[lft] = Tree[idx];
        Tree[rgt] = Tree[idx];

        Tree[idx] = 0;
    }

    if (e <= mid)           Update(lft,l,mid,s,e,v);
    else if (s > mid)       Update(rgt,mid+1,r,s,e,v);
    else                    Update(lft,l,mid,s,mid,v), Update(rgt,mid+1,r,mid+1,e,v);
}

int Query(int idx,int l,int r,int p)
{
    if (l == r)     return Tree[idx];

    if(Tree[idx])
    {
        Tree[lft] = Tree[idx];
        Tree[rgt] = Tree[idx];

        Tree[idx] = 0;
    }

    if (p <= mid)           Query(lft,l,mid,p);
    else                    Query(rgt,mid+1,r,p);
}

void Dfs(int u,int p,int l)
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

void HLD(int u,int p)
{
    if (Start[chainNo] == 0)
        Start[chainNo] = u;

    chainID[u] = chainNo;
    pos[u] = ++ptr;
    cvr[u][0] = ptr;

    int sc = -1, mx = -1;

    for (int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if ( v!= p && subTree[v] > mx)
        {
            sc = i;
            mx = subTree[v];
        }
    }

    if (sc != -1 )      HLD(adj[u][sc],u);

    for (int i=0; i<adj[u].size(); i++)
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

void UpdateAncestor(int u,int n)
{
    while(u != -1)
    {
        int uChain = chainID[ u ];
        int st = Start[uChain];

        Update(1,1,n,pos[st],pos[u],2);
        u = T[st];
    }
}

void UpdateChild(int u,int n)
{
    int st = cvr[u][0];
    int ed = cvr[u][1];

    Update(1,1,n,st,ed,1);
}


int main()
{
    DI(n);
    Build(1,1,n);

    for (int i=1; i<n; i++)
    {
        DII(u,v);

        adj[u].PB(v);
        adj[v].PB(u);
    }

    chainNo = 1;
    ptr = 0;

    Dfs(1,-1,0);
    HLD(1,-1);

    DI(q);

    while(q--)
    {
        DII(x,y);

        if (x == 1)     UpdateChild(y,n);
        if (x == 2)     UpdateAncestor(y,n);
        if (x == 3)     P("%d\n",Query(1,1,n,pos[y])%2);
    }
    return 0;
}
