
#include<bits/stdc++.h>
#define I int
#define LL long long int
#define UL unsigned long long int
#define D double
#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PB push_back
#define PT(t) printf("Case %d: ",t)
#define F(I1,a,b) for(int I1=a;I1<=b;I1++)
#define FI first
#define SD second
#define SC scanf
#define PC printf
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
using namespace std;
////////define value//////////
#define MX 2147483645LL
#define MD  1000000007LL
#define eps 1e-6
typedef pair<int,int>P;
vector<P>v[50003];
int n;
int lev[50003];
int par[50003];
int dis[50003];
void dfs(int i,int j,int l)
{
    par[i]=j;
    lev[i]=l;
    for(int k=0; k<v[i].size(); k++)
    {
        int h=v[i][k].first;
        int h1=v[i][k].second;
        if(h!=j)
        {
            dis[h]=dis[i]+h1;
            dfs(h,i,l+1);
        }
    }
    return ;
}
int tab[50007][30];
void preprocess()
{
    F(i,0,n-1)tab[i][0]=par[i];

    for(int i=1; 1<<i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(tab[j][i-1]!=-1) tab[j][i]=tab[tab[j][i-1]][i-1];
        }
}
int lca(int a,int b)
{
    if(lev[a]>lev[b])swap(a,b);
    for(int i=20; i>=0; i--)
    {
        if(lev[b]-(1<<i)>=lev[a]&&lev[b]>=(1<<i))
        {
            b=tab[b][i];
        }
    }
    if(a==b)return a;
    for(int i=20; i>=0; i--)
    {
        if(tab[a][i]!=-1&&tab[a][i]!=tab[b][i])
        {
            a=tab[a][i],b=tab[b][i];

        }
    }
    return par[a];
}
int main()
{

    S(n);
    F(t,1,n-1)
    {
        int x,y,z;
        S3(x,y,z);
        v[x].PB(make_pair(y,z));
        v[y].PB(make_pair(x,z));
    }
    dis[0]=0;
    dfs(0,0,1);
    SETR(tab);
    preprocess();
    int m;
    S(m);
    F(i,1,m)
    {
        int x,y;
        S2(x,y);
        int h=lca(x,y);
        PC("%d\n",dis[x]+dis[y]-2*dis[h]);
    }

    return 0;
}
