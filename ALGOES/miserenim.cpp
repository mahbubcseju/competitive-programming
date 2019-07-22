/*
Alice and Bob are playing game of Misère Nim. Misère Nim is a game playing on k piles of stones, each pile containing one or more stones. The players alternate turns and in each turn a player can select one of the piles and can remove as many stones from that pile unless the pile is empty. In each turn a player must remove at least one stone from any pile. Alice starts first. The player who removes the last stone loses the game.
Input
Input starts with an integer T (≤ 200), denoting the number of test cases.
Each case starts with a line containing an integer k (1 ≤ k ≤ 100). The next line contains k space separated integers denoting the number of stones in each pile. The number of stones in a pile lies in the range [1, 109].
Output
For each case, print the case number and 'Alice' if Alice wins otherwise print 'Bob'.
3
4
2 3 4 5
5
1 1 2 4 10
1
1
Case 1: Bob
Case 2: Alice
Case 3: Bob
*/

#include<bits/stdc++.h>
#define ll long long
#define I(a) scanf("%lld",&a)
using namespace std;
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++)
    {
        ll n;
        I(n);
        ll res=0;
        ll co=0;
        bool fl=0;
        for(int i=1; i<=n; i++)
        {
            ll x;
            I(x);
            if(x==1)co++;
            res^=x;
        }
        printf("Case %d: ",t);
        if(co==n)
        {
            if(co%2==1)
            printf("Bob\n");
            else printf("Alice\n");

        }
        else
        {
            if(res==0)printf("Bob\n");
            else printf("Alice\n");

        }
    }
    return 0;
}

