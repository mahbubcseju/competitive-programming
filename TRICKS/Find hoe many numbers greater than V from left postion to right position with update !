/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <deque>
#include <climits>
#include <complex>
#include <bitset>
#include <limits>
#define ll long long int
#define ull unsigned long long int
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PI(a) printf("%d",a)
#define PL(a) printf("%lld",a)
#define PT(t) printf("Case %d: ",t)
#define PB push_back
#define x first
#define y second
#define xx first.first
#define xy first.second
#define yx second.first
#define yy second.second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())-1
#define f(i,a,b) for(int i=a;i<=b; i++)
#define fr(i,a,b) for(int i=a;i<=b; i++)
#define frr(i,a,b) for(int i=a;i>=b; i--)
#define frv(i,a)  for(int i=0;i<a.size();i++)
//#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define Endl "\n"
#define mk make_pair
using namespace std;
template <class T> inline T BM(T p, T e, T M) {
    ll ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M) {
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e) {
    ll ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
template <class T>string NTS ( T Number ) {
    stringstream ss;
    ss << Number;
    return ss.str();
}
template <class T>T stringtonumber ( const string &Text ) {
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
template <class T>bool ISLEFT ( T a, T b, T c) {
    if (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 200000ll
#define md1 23377788ll
#define md 1000000007ll
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29

typedef pair<ll,ll>P;
//////////////////////////
/////////////////////////
int n;
int ar[mx+2];
int bu[mx+2];
int sq;
void init() {
    sq=sqrt(n+.0)+1;



    fr(i,0,n-1)bu[i]=ar[i];
    for(int i=0; i*sq<n; i++) {
        int l=i*sq;
        int r=min((i+1)*sq-1,n);
        sort(bu+l,bu+r+1);
    }
}
// How many numbers are there from l to ri greater than v
int qug(int l,int r,int v) {
    int nl=l/sq,nr=r/sq;
    int res=0;
    if(nl==nr) {
        fr(i,l,r)if(ar[i]>v)res++;
        return res;
    }
    for(int i=l,j=(nl+1)*sq-1; i<=j; i++)if(ar[i]>v)res++;
    for(int i=nl+1; i<nr; i++) {
        int lo=i*sq;
        int hi=min((i+1)*sq-1,n);
        int sesh=hi;
        int ans=0;
        while(lo<=hi) {
            int mid=(lo+hi)/2;
            if(bu[mid]>v) {
                ans=(sesh-mid+1);
                hi=mid-1;
            } else lo=mid+1;
        }
        res+=ans;
    }
    for(int i=nr*sq; i<=r; i++)if(ar[i]>v)res++;
    return res;

}
// How many numbers are there from l to ri less than v
int qul(int l,int r,int v) {
    int nl=l/sq,nr=r/sq;
    int res=0;
    if(nl==nr) {
        fr(i,l,r)if(ar[i]<v)res++;
        return res;
    }
    for(int i=l,j=(nl+1)*sq-1; i<=j; i++)if(ar[i]<v)res++;
    for(int i=nl+1; i<nr; i++) {
        int lo=i*sq;
        int hi=min((i+1)*sq-1,n);
        int suru=lo;
        int ans=0;
        while(lo<=hi) {
            int mid=(lo+hi)/2;
            if(bu[mid]<v) {
                ans=(mid-suru+1);
                lo=mid+1;
            } else hi=mid-1;
        }
        res+=ans;
    }
    for(int i=nr*sq; i<=r; i++)if(ar[i]<v)res++;
    return res;

}

void update(int in,int val)
{
    int s=in/sq;
    int l=s*sq;
    int r=min(n,(s+1)*sq-1);
    ar[in]=val;
    for(int i=l;i<=r;i++)bu[i]=ar[i];
    sort(bu+l,bu+r+1);
}

ll ans;
void  qu(int x,int y) {
    if(x==y)return;
    ll sum=qul(x,y-1,ar[y]);
    sum-=qug(x,y-1,ar[y]);
    sum+=qug(x+1,y,ar[x]);
    sum-=qul(x+1,y,ar[x]);
    if(ar[x]>ar[y])sum++;
    else sum--;

    ans+=sum;
    swap(ar[x],ar[y]);
    update(x,ar[x]);
    update(y,ar[y]);

}

int main() {
    int m;
    I2(n,m);
    fr(i,0,n-1)ar[i]=i;
    init();
    while(m--) {
        int x,y;
        I2(x,y);
        x--,y--;
        if(x>y)swap(x,y);
        qu(x,y);
        PL(ans);
        NL;

    }

    return 0;
}
