
#include<bits/stdc++.h>
#define I int
#define LL long long int
#define UL unsigned long long int
#define D double
#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SL(a) scanf("%lld",&a)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define F(I1,a,b) for(int I1=a;I1<=b;I1++)
#define FR(I2,a,b) for(int I2=a;I2>=b;I2--)
#define FL(J,a,b) for(long long J=a;J<=b;J++)
#define FLR(J1,a,b) for(long long J1=a;J1>=b;J1--)
#define IT(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define ITP(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
#define PB(a) push_back(a)
#define xx first
#define yy second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<LL>(a)
using namespace std;
template <class T> inline T BM(T p,T e,T M)
{
    LL ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T MDINV(T a,T M)
{
    return BM(a,M-2,M);
}
template <class T> inline T PW(T p,T e)
{
    LL ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
template <class T>string NTS ( T Number )
{
    stringstream ss;
    ss << Number;
    return ss.str();
}
template <class T>T stringtonumber ( const string &Text )
{
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
typedef pair<int ,int >P;
////////define value//////////
#define MX 3000000
#define MD    1000000007LL
#define eps FLT_EPSILON
/////////////////////////////
////////////////////////////
////Function Area Start////
char ch[10005];
LL hishab(LL l,LL s,LL e)
{
    if(l<s)return 0;
    e=min(e,l);
    LL sum=(e-s+1)*(s+e-2)/2;
    LL  su=(e-s+1)*l;
    return su-sum;
}
LL step[20][10007];
struct da
{
    LL x,y,in;
    da()
    {

    }
    da(LL _x,LL _y,LL _in)
    {
        x=_x,y=_y,in=_in;
    }
    bool operator<(const da &p)const
    {
        return (x==p.x?(y==p.y?in<p.in:y<p.y):x<p.x);
    }
};
da arr[10007];
int main()
{
    int tc;
    S(tc);
    F(t,1,tc)
    {
        scanf("%s",ch+1);
        LL n,m;
        SL2(n,m);
        LL l=strlen(ch+1);
        LL ans=hishab(l,n,m);
        for(LL i=1; i<=l; i++)
        {
            step[0][i]=ch[i]-'a';
        }
        LL s=0;
        for( LL st=1, co=1; co<=l; st++,co*=2)
        {
            s++;
            for(LL i=1; i<=l; i++)
            {
                arr[i].x=step[st-1][i];
                arr[i].y=i+co<=l?step[st-1][i+co]:-1;
                arr[i].in=i;
            }
            sort(arr+1,arr+l+1);
            for(LL i=1; i<=l; i++)
            {
                step[st][arr[i].in]=(i-1>0&&arr[i].x==arr[i-1].x&&arr[i].y==arr[i-1].y)?step[st][arr[i-1].in]:i;
            }
        }
        LL lcp[l+3];
        LL sum=0;
        step[s][l+1]=-2;
        for(LL i=1; i<l; i++)
        {
            LL x=arr[i].in;
            LL y=arr[i+1].in;
            for(LL j=s; j>=0; j--)
            {
                if(step[j][x]==step[j][y])
                {
                    x+=(1LL<<j);
                    y+=(1LL<<j);
                }
                if(x>l|y>l)break;
            }
            lcp[i]=(x-arr[i].in);
            sum+=min(m,lcp[i])>=n?min(m,lcp[i])-n+1:0;

        }
        PT(t);
        PL(ans-sum);

    }
    return 0;
}
