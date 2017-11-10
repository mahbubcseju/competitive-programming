/*
As the name says, this problem is about finding the number of points in a rectangle whose sides are parallel to axis. All the points and rectangles consist of 2D Cartesian co-ordinates. A point that lies in the boundary of a rectangle is considered inside.
Input
Input starts with an integer T (≤ 10), denoting the number of test cases.
Each case starts with a line containing an integer q (1 ≤ q ≤ 30000) denoting the number of queries. Each query is either one of the following:
1)      0 x y, meaning that you have got a new point whose co-ordinate is (x, y). But the restriction is that, if a point (x, y) is already listed, then this query has no effect.
2)      1 x1 y1 x2 y2 meaning that you are given a rectangle whose lower left co-ordinate is (x1, y1) and upper-right corner is (x2, y2); your task is to find the number of points, given so far, that lie inside this rectangle. You can assume that (x1 < x2, y1 < y2).
You can assume that the values of the co-ordinates lie between 0 and 1000 (inclusive).
Output
For each case, print the case number in a line first. Then for each query type (2), you have to answer the number of points that lie inside that rectangle. Print each of the results in separated lines.
1
9
0 1 1
0 2 6
1 1 1 6 6
1 2 2 5 5
0 5 5
1 0 0 6 5
0 3 3
0 2 6
1 2 1 10 10
Case 1:
2
0
2
3
*/
#include<bits/stdc++.h>
#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define SET(a) memset(a,0,sizeof a)
#define PC printf
#define P(a) printf("%d\n",a)
using namespace std;
#define MX 1002
#define MD  1000000007LL
#define eps 1e-6
int a[1003][1003];
bool b1[1003][1003];
void update(int x,int y)
{
    while(x<=MX)
    {
        int yy=y;
        while(yy<=MX)
        {
            a[x][yy]+=1;
            yy+=yy&-yy;
        }
        x+=x&-x;
    }
}
int res(int x,int y)
{
    int sum=0;
    while(x>0)
    {
        int yy=y;
        while(yy>0)
        {
            sum+=a[x][yy];
            yy-=yy&-yy;
        }
        x-=x&-x;
    }
    return sum;
}

int main()
{
    int tc;
    S(tc);
    for(int t=1; t<=tc; t++)
    {
        int n;
        S(n);
        SET(a);
        SET(b1);
        PC("Case %d:\n",t);
        for(int i=1; i<=n; i++)
        {
            int x;
            S(x);
            if(x==0)
            {
                int y,z;
                S2(y,z);
                y++;
                z++;
                if(b1[y][z]==0)
                    update(y,z);
                b1[y][z]=1;
            }
            else
            {
                int b,c,y,z;
                S2(b,c);
                b++,c++;
                S2(y,z);
                y++,z++;
                int r=res(y,z);
                int p=y;
                int q=c;
                q--;
                if(q>0)
                    r-=res(p,q);
                b--;
                if(b>0)r-=res(b,z);
                if(b>0&&q>0)r+=res(b,q);
                P(r);
            }
        }

    }
    return 0;
}
