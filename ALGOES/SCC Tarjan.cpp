#include<bits/stdc++.h>
#define ll long long
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define P(a) printf("%d\n",a)
#define PB(a) push_back(a)
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
using namespace std;
#define mx 50004
#define md 2000000000000000000ll
typedef pair<int, int >P;
typedef vector<ll>V;

////////define value/////
V a[mx];
int n,sz,kd;
int low[mx],ind[mx];
int vis[mx];
stack<int>st;
int kdb[mx];//koto number component er element.
int kda ;// Counting component number;

void dfs(int u)
{
    vis[u]=kd;
    low[u]=ind[u]=++sz;
    st.push(u);
    for(int j=0; j<a[u].size(); j++)
    {
        int x=a[u][j];
        if(vis[x]==-1)
        {

            dfs(x);
            low[u]=min(low[u],low[x]);

        }
        else if(kdb[x]==0)
        {
            low[u]=min(low[u],low[x]);
        }

    }
    if(low[u]==ind[u])
    {
        kdb[u]=++kda;
        int y;
        do
        {
            y=st.top();
            kdb[y]=kda;
            st.pop();
        }
        while(y!=u);
    }

}

void tarjan()
{
    kda=0;
    kd=0;
    sz=0;
    SETR(vis);
    for(int i=1; i<=n; i++)
    {
        if(vis[i]==-1)
        {
            ++kd;
            dfs(i);
        }
    }
}

int main()
{

    int tc,cs=0;
    I(tc);
    while (tc--)
    {
        I(n);
        for(int i=1; i<=n; i++)
        {
            int x,y;
            I2(x,y);
            a[x].PB(y);
        }
        tarjan();

        for(int i=0; i<=n; i++)a[i].clear();

    }
    return 0;
}
