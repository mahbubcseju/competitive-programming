/*How many articulation point a graph has loj 1063 */

#include<bits/stdc++.h>
#define I int
#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define PB(a) push_back(a)
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
using namespace std;
#define MX 1000000000
#define MD 100000007
vector<int>v[10009];
int par[10009];//already visited er distance
int lo[10009];// point er nicher kew uporrer karo sathe connect kina check
int cnt;
int res=0;
void art(int u)
{
    par[u]=lo[u]=++cnt;
    int ch=0,bl=0;
    for(int i=0; i<v[u].size(); i++)
    {

        int u1=v[u][i];
        if(par[u1]==0)
        {
            art(u1);
            lo[u]=min(lo[u],lo[u1]);
            if(par[u]<=lo[u1])ch++;
            bl++;
        }
        else
        {
            lo[u]=min(lo[u],par[u1]);
        }
    }
    if(u==1&&bl>1)res++;
    else if(u>1&&ch!=0)res++;


}
int main()
{

    int tc;
    S(tc);
    for(int t=1; t<=tc; t++)
    {
        int n,m;
        S2(n,m);
        SET(par);
        SET(lo);
        cnt=0;
        res=0;
        int x,y;
        for(int i=1; i<=m; i++)
        {
            S2(x,y);
            v[x].PB(y);
            v[y].PB(x);
        }
        art(1);
        for(int i=0; i<=n; i++)v[i].clear();
        PT(t);
        P(res);

    }

    return 0;
}
