#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define xx first
#define yy second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
//#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ull>(a)
#define lol printf("BUG\n")
#define mk make_pair
using namespace std;

template <class T> inline T PW(T p, T e)
{
    ull ret = 1ull;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
template <class T>T stringtonumber ( const string &Text )
{
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0ull;
}
ull add(ull a,ull b,ull c)
{
    //cout<<a<<b<<c<<endl;
    ull x=c-a;
    if(x<=b)
    {
        ull cop=c-a;
        cop=b-cop;
        // cout<<cop<<endl;
        return cop;
    }
    //cout<<a+b<<endl;
    return a+b;
}
ull mul(ull p,ull e,ull mod)
{
    //cout<<p<<e<<mod<<endl;
    ull ret = 0;
    for(; e > 0; e >>= 1)
    {
        if(e & 1ull)
        {
            ret = add(ret,p,mod);
        }
        p = add(p,p,mod);
    }
    //cout<<ret<<endl;
    return ret;
}
ull PW1(ull p, ull e,ull mod)
{
    ull ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1ull) ret = mul(ret,p,mod);
        p = mul(p,p,mod);
    }
    return ret;
}
int main()
{

    int tc,cs=0;
    I(tc);
    while(tc--)
    {

        ull a,b;
        string c;
        cin>>a>>b>>c;
        ull res;
        if(c=="18446744073709551616")
        {
            res=PW(a,b);
        }
        else
        {
            ull mod=STN(c);
            a%=mod;
            res=PW1(a,b,STN(c));
        }
        PC("%llu\n",res);

    }
    return 0;
}
