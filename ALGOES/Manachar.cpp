/*
! Given a string of at most 1000000 characters find and print the length of the largest palindrome inside this string.
*/
#include<cfloat>
#include<climits>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;
char s[2000020];
char T[2000020];
// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking

void  preprocess()
{
    int n = strlen(s);
    if (n == 0)
    {
        strcpy(T,"^$");
        return ;
    }
    int len=0;
    T[len++]='^';
    for (int i = 0; i < n; i++)
    {
        T[len++]='#';
        T[len++]=s[i];

    }
    T[len++]='#';
    T[len++]='$';
    T[len]='\0';
    return ;
}


int  longestPalindrome()
{
    preprocess();

    int n = strlen(T);
    int P[n+2];
    int C = 0, R = 0;
    for (int i = 1; i < n-1; i++)
    {
        int i_mirror = 2*C-i; // equals to i' = C - (i-C)

        P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;

        // Attempt to expand palindrome centered at i
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
            P[i]++;

        // If palindrome centered at i expand past R,
        // adjust center based on expanded palindrome.
        if (i + P[i] > R)
        {
            C = i;
            R = i + P[i];
        }
    }

    // Find the maximum element in P.
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n-1; i++)
    {
        if (P[i] > maxLen)
        {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    //  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
    return maxLen;
}
int main()
{
    int cs=0;

    while(scanf("%s",s))
    {
        if(!strcmp(s,"END"))break;
        int l= longestPalindrome();
        printf("Case %d: %d\n",++cs,l);
    }
    return 0;
}
