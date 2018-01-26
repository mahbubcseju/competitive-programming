
#include<bits/stdc++.h>
#define ll long long int
#define SL(a) scanf("%d",&a)
#define SL2(a,b) scanf("%d%d",&a,&b)
#define SL3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define S(a) scanf("%lld",&a)
#define S2(a,b) scanf("%lld%lld",&a,&b)
#define S3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PL(a) printf("%d\n",a)
#define P(a) printf("%lld\n",a)
#define PT(t) printf("Case %lld: ",t)
#define PB(a) push_back(a)
#define xx first
#define yy second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())

using namespace std;

typedef pair<ll, ll  >P;

////////define value//////////
pair<ll, pair<ll, ll> >euclid(ll x, ll y)
{
    //120x+23y=1;
    ll a = 1, b = 0; //x=1*x+0*y;//120=120*1+23*0;
    ll a1 = 0, b1 = 1; //y=0*x+1*y;//23=120*0+23*1;
    while(y != 0 )
    {
        ll md = x % y;
        ll res = x / y;
        //120%23=5
        //120/23=5
        //md=x-y*res;
        //5=(1*120+0*23)-(0*120+1*23)*5;
        ll a2 = a - (a1 * res);
        ll b2 = b - (b1 * res);
        x = y;
        y = md;
        a = a1, b = b1;
        a1 = a2, b1 = b2;
    }
    return make_pair(x, make_pair(a, b));
}
int main()
{
    ll m, n;
    while(cin >> m >> n)
    {
        pair<ll, pair<ll, ll> > op = euclid(m, n);
        PC("%lld %lld %lld\n", op.yy.xx, op.yy.yy, op.xx);
    }
    return 0;
}
