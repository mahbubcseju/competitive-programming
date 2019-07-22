
/*
A Hyper Knight is like a chess knight except it has some special moves that a regular knight cannot do. Alice and Bob are playing this game (you may wonder why they always play these games!). As always, they both alternate turns, play optimally and Alice starts first. For this game, there are 6 valid moves for a hyper knight, and they are shown in the following figure (circle shows the knight).
They are playing the game in an infinite chessboard where the upper left cell is (0, 0), the cell right to (0, 0) is (0, 1). There are some hyper knights in the board initially and in each turn a player selects a knight and gives a valid knight move as given. And the player who cannot make a valid move loses. Multiple knights can go to the same cell, but exactly one knight should be moved in each turn.
Now you are given the initial knight positions in the board, you have to find the winner of the game.
Input
Input starts with an integer T (≤ 200), denoting the number of test cases.
Each case starts with a line containing an integer n (1 ≤ n ≤ 1000) where n denotes the number of hyper knights. Each of the next n lines contains two integers x y (0 ≤ x, y < 500) denoting the position of a knight.
Output
For each case, print the case number and the name of the winning player
*/

#include<bits/stdc++.h>
#define ll long long
#define I(a) scanf("%d",&a)
using namespace std;
int vis[1009][1009];

int dx[]= {-1,-1,-2,-3,-2,1};
int dy[]= {-3,-2,-1,-1,1,-2};


int grandy(int x,int y)
{
    if(x<0||y<0)
    {
        return -1;
    }
    int &ret=vis[x][y];
    if(ret!=-1)return ret;
    int ar[7];
    for(int i=0; i<6; i++)
    {
        int x1=x+dx[i];
        int y1=y+dy[i];
        ar[i]=grandy(x1,y1);
    }
    sort(ar,ar+6);
    ret=0;
    for(int i=0; i<6; i++)
    {
        if(ret==ar[i])ret++;
    }
    return ret;
}

int main()
{
    int tc,cs=0;
    memset(vis,-1,sizeof vis);
    I(tc);
    while(tc--)
    {
        int n;
        I(n);
        int res=0;
        for(int i=1; i<=n; i++)
        {
            int x,y;
            I(x);
            I(y);
            res^=grandy(x,y);
        }
        if(res==0)printf("Case %d: Bob\n",++cs);
        else printf("Case %d: Alice\n",++cs);
    }
    return 0;
}
