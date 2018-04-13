/*
Problem Description
Dear contestant, now you are an excellent navy commander, who is responsible of a tough mission currently.
Your fleet unfortunately encountered an enemy fleet near the South Pole where the geographical conditions are negative for both sides. The floating ice and iceberg blocks battleships move which leads to this unexpected engagement highly dangerous, unpredictable and incontrollable.
But, fortunately, as an experienced navy commander, you are able to take opportunity to embattle the ships to maximize the utility of cannons on the battleships before the engagement.
The target is, arrange as many battleships as you can in the map. However, there are three rules so that you cannot do that arbitrary:
A battleship cannot lay on floating ice
A battleship cannot be placed on an iceberg
Two battleships cannot be arranged in the same row or column, unless one or more icebergs are in the middle of them.
input
There is only one integer T (0<T<12) at the beginning line, which means following T test cases.
For each test case, two integers m and n (1 <= m, n <= 50) are at the first line, represents the number of rows and columns of the battlefield map respectively. Following m lines contains n characters iteratively, each character belongs to one of ‘#’, ‘*’, ‘o’, that symbolize iceberg, ordinary sea and floating ice.
Output
For each case, output just one line, contains a single integer which represents the maximal possible number of battleships can be arranged.
Sample Input
2
4 4
*ooo
o###
**#*
ooo*
4 4
#***
*#**
**#*
ooo#
Sample Output
3
5
*/

#include<bits/stdc++.h>
#define ll long long int
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define PB(a) push_back(a)
#define SC scanf
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define mk make_pair
using namespace std;
#define mx 50004
#define md 1000000007ll
typedef pair<int, int >P;
typedef vector<int >V;
V a[2504];
int ro,co;
int r[54*54];
int c[54*54];
int li[50*50+3];
int vis[50*50+4];
bool dfs(int u)
{
    vis[u]=1;
    for(int i=0; i<a[u].size(); i++)
    {
        int v=a[u][i];
        int v1=r[v];
        if(vis[c[li[v1]]]==1)continue;
        if(li[v1]==-1||dfs(c[li[v1]]))
        {
            li[v1]=v;
            return true;
        }
    }
    return false;
}
int main()
{
    int tc;
    I(tc);
    while(tc--)
    {
        SETR(li);
        int n,m;
        I2(n,m);
        char ch[n+2][m+2];
        for(int i=1; i<=n; i++)
        {
            SC("%s",ch[i]+1);
        }
        ro=1;
        co=1;
        for(int i=1; i<=n; i++)
        {
            ++co;
            ++ro;
            for(int j=1; j<=m; j++)
            {
                if(ch[i][j]=='*')
                {
                    r[i*m+j]=ro;

                }
                else if(ch[i][j]=='#')
                {
                    ro++;
                }
                if(ch[j][i]=='*')
                {
                    c[j*m+i]=co;
                    a[co].PB(j*m+i);
                }
                else if(ch[j][i]=='#') co++;
            }
        }
        int ans=0;
        SETR(li);
        for(int i=1; i<=co; i++)
        {
            if(a[i].size()!=0)
            {

                SET(vis);
                 if(dfs(i))ans++;
            }
        }
        P(ans);
        for(int i=0; i<=co; i++)a[i].clear();
    }


    return 0;
}
