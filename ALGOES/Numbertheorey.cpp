/*Euler's totient function  applied to a positive integer n is defined to be the number of positive integers less than or equal to n that are relatively prime to n.  is read "phi of n."Given the general prime factorization of  n =p1^e1 p2^e2 ..pn^en , one can compute  using the formulaphi(n) =n(1-1/p1)(1-1/p2)..(1-1/pn)*/Seive:
way 1:
LL a[1000003];
LL b[1000003],sz;
void seive()
{   sz=0;
    SET(a);
    SET(b);
    a[++sz]=2;
    for(LL i=3; i<=MX; i+=2)
    {
        if(!b[i])
        {
            a[++sz]=i;
            for(LL j=i*3; j<=MX; j+=2*i)
            {
                b[j]=1;
            }
        }

    }
}
Seive :
Way 2:
int a[10009];
vector<int >v;
void seive()
{
    for(int i=3; i<=sqrt(M); i+=2)
    {
        if(a[i]==0)
            for(int j=i*3; j<=M; j+=2*i)
            {
                a[j]=1;
            }
    }

    v.push_back(2);
    for(int i=3; i<=M; i+=2)
    {
        if(a[i]==0)
        {
            v.push_back(i);
        }
    }

}
devisors finding :
LL a[1000003];
LL b[1000003],sz;
void seive()
{
    sz=0;
    SET(a);
    SET(b);
    a[++sz]=2;
    for(LL i=3; i<=MX; i+=2)
    {
        if(!b[i])
        {
            a[++sz]=i;
            for(LL j=i*3; j<=MX; j+=2*i)
            {
                b[j]=1;
            }
        }

    }
}
LL m,m1;
vector<pair<LL,LL> >v;
vector<LL >vn;
void  dp(LL i,LL num)
{
    if(i==v.size())return ;
    dp(i+1,num);
    for(LL j=1; j<=v[i].second; j++)
    {
        num*=v[i].first;
        vn.PB(num);
        dp(i+1,num);
    }
}
int main()
{
    seive();

    LL n;
    int t=0;
    while(cin>>n)
    {
        m1=n;
        for(LL i=1; i<=sz&&a[i]*a[i]<=n; i++)
        {
            LL co=0;
            while(n%a[i]==0)
            {
                n/=a[i];
                co++;
            }
            v.PB(make_pair(a[i],co));

        }
        if(n!=1) v.PB(make_pair(n,1));
        dp(0,1);
    }

    return 0;
}
Prime factorization:
LL a[1000003];
LL b[1000003],sz;
void seive()
{
    sz=0;
    SET(a);
    SET(b);
    a[++sz]=2;
    for(LL i=3; i<=MX; i+=2)
    {
        if(!b[i])
        {
            a[++sz]=i;
            for(LL j=i*3; j<=MX; j+=2*i)
            {
                b[j]=1;
            }
        }

    }
}
vector<pair<LL,LL> >v;
int main()
{
    seive();

    LL n;
    int t=0;
    while(cin>>n)
    {
        for(LL i=1; i<=sz&&a[i]*a[i]<=n; i++)
        {
            LL co=0;
            while(n%a[i]==0)
            {
                n/=a[i];
                co++;
            }
            v.PB(make_pair(a[i],co));

        }
        if(n!=1) v.PB(make_pair(n,1));
    }

    return 0;
}
suppose a number is factorized as 2^x * 3^y * 5^z, so, the total number of divisors is
(x + 1) * (y + 1) * (z + 1)
Now, the general formula is
If the prime factorization of an integer is
p1^x1 * p2^x2 * p3^x3 * ... * pn^xn
where, p1, p2, ..., pn are primes, then the number of divisors is

(x1 + 1) * (x2 + 1) * (x3 + 1) * ... * (xn + 1)

So, if the prime factorization of an integer is
p1^x1 * p2^x2 * p3^x3 * ... * pn^xn
where, p1, p2, ..., pn are primes, then the summation of divisors is
(p1^(x1+1)-1)/(p1-1)*(p2^(x2+1)-1)/(p2-1)*.....*(pn^(xn+1)-1)/(pn-1)






Number of co prime :
    num*(1-(1/p1))*(1-(1/p2))------



how :
    12 prime 2,3
    now exclusion inclusion:
       12-12/2-12/3+12/6
       12(1-1/2-1/3+1/6)
       12{1(1-1/2)-1/3(1-1/2)}
       12(1-1/2)(1-1/3)
       num*(1-(1/p1))*(1-(1/p2))------
