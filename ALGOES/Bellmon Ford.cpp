/*Given a directed graph. U have to say From which postions u start korle cycle a porba ao negative cycle
*/
#include<bits/stdc++.h>
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define SET(a) memset(a,0,sizeof a)
#define PC printf
#define PB push_back
#define P(a) printf("%d\n",a)
#define mk make_pair
#define xx first
#define yy second
using namespace std;
#define mx 1000000000
#define MD  1000000007LL
#define eps 1e-6
typedef pair<int,int>P;
int main()
{
    int tc,cs=0;
    I(tc);
    while(tc--)
    {
        int n,m;
        I2(n,m);
        pair<P,int>a[n+m+3];
        vector< int >v[n+2];

        int res[n+2];
        for(int i=1; i<=n; i++)res[i]=mx;
        res[0]=0;

        for(int i=1; i<=m; i++)
        {
            int x,y,z;
            I2(x,y);
            I(z);
            x++;
            y++;
            v[y].PB(x);//For reverse graph
            a[i]=mk(mk(y,x),z);//For reverse graph
        }
        for(int i=1; i<=n; i++)
        {
            a[++m]=mk(mk(0,i),0);
        }

        sort(a+1,a+m+1);
        //Bellmonford Partŝ
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                int x=a[j].xx.xx;
                int y=a[j].xx.yy;
                int z=a[j].yy;
                if(res[x]<mx&&res[x]+z<res[y])
                {
                    res[y]=res[x]+z;
                }
            }
        }
        //Cycle check and ans finding
        queue<int>q;
        int vis[n+3];
        SET(vis);
        bool fl=0;
        for(int j=1; j<=m; j++)
        {
            int x=a[j].xx.xx;
            int y=a[j].xx.yy;
            int z=a[j].yy;
            if(res[x]<mx&&res[x]+z<res[y]&&vis[y]==0)
            {
                fl=1;
                vis[y]=1;
                q.push(y);
                while(!q.empty())
                {
                    int f=q.front();
                    q.pop();
                    for(int i=0; i<v[f].size(); i++)
                    {
                        int u=v[f][i];
                        if(vis[u]==0)
                        {
                            vis[u]=1;
                            q.push(u);
                        }
                    }
                }

            }
        }
        printf("Case %d:",++cs);
        if(fl==0)
        {
            printf(" impossible");
        }
        else{
            for(int i=1; i<=n; i++)
            {
                if(vis[i])
                    printf(" %d",i-1);
            }
        }
        printf("\n");
    }
    return 0;
}
