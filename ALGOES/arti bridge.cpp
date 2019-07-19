/*Show the articualtion Bridge*/

#include<bits/stdc++.h>
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define SET(a) memset(a,0,sizeof a)
#define PC printf
#define PB push_back
#define P(a) printf("%d\n",a)
using namespace std;
#define mx 10000
#define MD  1000000007LL
#define eps 1e-6
typedef pair<int,int>P;
vector<int>v[mx+4];
int vis[mx+4];
int lo[mx+4];
int hi[mx+4];
P  a[mx+4];
int sz;
int br;
void bridge(int u,int par)
{
    lo[u]=hi[u]=++sz;
    vis[u]=1;
    for(int i=0; i<v[u].size(); i++)
    {
        int x=v[u][i];
        if(x==par)continue;

        if(vis[x]==0)
        {
            bridge(x,u);
            lo[u]=min(lo[u],lo[x]);
            if(hi[u]<lo[x])
            {
                a[++br]=make_pair(min(u,x),max(u,x));
            }
        }
        else
        {
            lo[u]=min(lo[u],hi[x]);

        }

    }
}

int main()
{

    int tc,cs=0;
    I(tc);
    while(tc--)
    {
        SET(vis);
        SET(lo);
        SET(hi);
        sz=0;
        br=0;
        int n;
        I(n);
        for(int i=1; i<=n; i++)
        {

            int u;
            I(u);
            char ch[10];
            scanf("%s",ch);
            int len=strlen(ch);
            int no=0;
            for(int j=1; j<len-1; j++)
            {
                no=no*10+ch[j]-'0';
            }
            for(int j=1; j<=no; j++)
            {
                int x;
                I(x);
                v[u].PB(x);
               // v[x].PB(u);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)bridge(i,-1);
        }
        PC("Case %d:\n",++cs);
        PC("%d critical links\n",br);
        sort(a+1,a+br+1);
        for(int i=1; i<=br; i++)
        {
            PC("%d - %d\n",a[i].first,a[i].second);
        }

        for(int i=0; i<=n; i++)v[i].clear();
    }
    return 0;
}

