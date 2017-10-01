#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define SC scanf
#define S2(a,b)  scanf("%lld %lld",&a,&b)
#define mx 100000ll
#define md 1000000007ll
#define B 31ll
char ch[mx+3];
ll hash_ch[mx+3];
ll hash_ul[mx+3];
ll bm[mx+3];
ll mdi[mx+3];
template <class T> inline T BM(T p, T e, T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T MDINV(T a, T M)
{
    return BM(a, M - 2, M);
}
void cal()
{
    ll res=1;
    for(ll i=0; i<=mx; i++)
    {
        bm[i]=res;
        mdi[i]=MDINV(res,md);
        res=(res*B)%md;
    }
}

void hash_function(ll hash_st[])
{
    ll len=strlen(ch);
    ll bp=1;
    ll res=0;
    for(ll i=0; i<len; i++)
    {
        res=(res+(ch[i]-96)*bp)%md;
        hash_st[i]=res;
        bp=(bp*B)%md;
    }

}
ll len;
ll go(ll st,ll en,ll op)
{
    ll re=0;
    if(op==1)
    {
        st--;
        en--;
        re=hash_ch[en];
        if(st>0)
        {
            re-=hash_ch[st-1];
            if(re<0)re+=md;
            re=(re*mdi[st])%md;

        }
    }
    else
    {
        st=len-st;

        en=len-en;
        swap(st,en);
        re=hash_ul[en];
        if(st>0)
        {
            re-=hash_ul[st-1];
            if(re<0)re+=md;
            re=(re*mdi[st])%md;

        }
    }
    return re;

}
int main()
{

    SC("%s",ch);
    len=strlen(ch);
    cal();
    hash_function(hash_ch);
    reverse(ch,ch+len);
    hash_function(hash_ul);
    ll st,en;
    S2(st,en);
    cout<< go(st,en,1);//left to right hash
    cout<< go(st,en,2);//Right to left hash
    return 0;
}
