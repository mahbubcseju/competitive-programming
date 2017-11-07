/*
In 'MonkeyLand', there is a traditional game called "Bamboo Climbing". The rules of the game are as follows:
1)       There are N monkeys who play this game and there are N bamboos of equal heights. Let the height be L meters.
2)       Each monkey stands in front of a bamboo and every monkey is assigned a different bamboo.
3)       When the whistle is blown, the monkeys start climbing the bamboos and they are not allowed
            to jump to a different bamboo throughout the game.
4)       Since they are monkeys, they usually climb by jumping. And in each jump, the ith monkey can
          jump exactly pi meters (pi is a prime). After a while when a monkey finds that he cannot jump
        because one more jump may get him out of the bamboo, he reports the remaining length ri that he is not able to cover.
5)       And before the game, each monkey is assigned a distinct pi.
6)       The monkey, who has the lowest ri, wins.
Now, the organizers have found all the information of the game last year, but unluckily they haven't found the height of the bamboo. To be more exact, they know N, all pi and corresponding ri, but not L. So, you came forward and found the task challenging and so, you want to find L, from the given information.
Input
Input starts with an integer T (≤ 10000), denoting the number of test cases.
Each case starts with a line containing an integer n (1 ≤ n ≤ 12). Each of the next n lines contains two integers pi (1 < pi < 40,
pi is a prime) and ri (0 < ri < pi). All pi will be distinct.
Output
For each case, print the case number and the minimum possible value of L that satisfies the above conditions. If there is no solution, print 'Impossible'.
2
3
5 4
7 6
11 3
4
2 1
3 2
5 3
7 1
Case 1: 69
Case 2: 113
*/

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
    ll tc;
    S(tc);
    for(ll t = 1; t <= tc; t++)
    {
        ll n;
        S(n);
        P a[n+2];
        for(ll i=1;i<=n;i++)
        {
            S2(a[i].xx,a[i].yy);//mod,modval

        }
        ll x=a[1].yy,y=a[1].xx;//x=4(mod 5)//x=4+5t
        bool  fl=0;
        for(ll i=2;i<=n;i++)
        {
            //a[i].xx=7,a[i].yy=6;
            //4+5t=6(mod7)
            //5t=6-4(mod7)
            //t=1/2*2(mod7)
            //t=val=yy+35t;
            //new x=4+5*(val=yy+35t)
            ll mi=a[i].yy-x;
            //modinverse part
            //t=1/2(mod 7)
            //2t=1(mod 7)
            //2t=1+7l
            //2t-7l=1;
            //now apply ex eu

            pair<ll,pair<ll,ll> > p=euclid(y,a[i].xx);
            if(p.xx!=1){
                fl=1;
                break;
            }
            ll k=mi*p.yy.xx;
            k=(k%a[i].xx+a[i].xx)%a[i].xx;
            x=x+k*y;
            y=y*a[i].xx;
        }

        PT(t);
        if(fl==0)
        P(x);
        else PC("Impossible\n");
    }
    return 0;
}
