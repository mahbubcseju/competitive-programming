#include<bits/stdc++.h>
#define ll long long int
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PI(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define PB push_back
#define xx first
#define yy second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define mk make_pair
using namespace std;
#define mx  200
#define md 1000000007
#define maxp 1000004
typedef pair<int , int >P;
typedef vector<int >V;

////////define value/////
int par[mx+3];

int fifr(int u)
{
    if(par[u]==u)return u;
    return par[u]=fifr(par[u]);
}

int main()
{
    int tc,cs=0;
    I(tc);
    while(tc--)
    {
        int n,m;
        I2(n,m);
        PC("Case %d:\n",++cs);
        pair<int,P>a[202],b[202];
        int sz=0;
        for(int i=1;i<=m;i++)
        {
            int x,y,z;
            I3(x,y,z);
            a[++sz]=mk(z,mk(x,y));
            sort(a+1,a+sz+1);
            for(int j=1;j<=n;j++)par[j]=j;
            int s=0;
            int res=0;
            for(int j=1;j<=sz;j++)
            {
                int u=fifr(a[j].yy.xx);
                int v=fifr(a[j].yy.yy);
                if(u!=v)
                {
                    b[++s]=a[j];
                    par[u]=v;
                    res+=a[j].xx;
                }
                if(s==n-1)break;
            }
            if(s!=n-1)PI(-1);
            else PI(res);
            sz=0;
            for(int i=1;i<=s;i++)
            {
                a[++sz]=b[i];
            }

        }


    }

    return 0;
}
