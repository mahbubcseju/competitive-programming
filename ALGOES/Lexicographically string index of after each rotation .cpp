//ITS Not my code //JUst for testing //
//Sorry
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
#include<string.h>
using namespace std;
#define MX 1000000
char sub[MX+2];
int len;

int MinLex( )
{
    int lft=0,rgt=1,ln=0;
    while( lft<len && rgt<len && ln<len )
    {
        int t=sub[ (lft+ln)%len ]-sub[ (rgt+ln)%len ];
        if(t==0) ln++;
        else
        {
            if(t>0)lft=lft+ln+1;//For Lexismall t>0
            else rgt=rgt+ln+1;
            if(lft==rgt)rgt++;
            ln=0;
        }
    }
    return min(lft,rgt);
}

int MaxLex( )
{
    int lft=0,rgt=1,ln=0;
    while( lft<len && rgt<len && ln<len )
    {
        int t=sub[ (lft+ln)%len ]-sub[ (rgt+ln)%len ];
        if(t==0) ln++;
        else
        {
            if(t<0)lft=lft+ln+1;//For lexiLarge t<0
            else rgt=rgt+ln+1;
            if(lft==rgt)rgt++;
            ln=0;
        }
    }
    return min(lft,rgt);
}
int main()
{
    while( scanf("%s",sub)==1 )
    {
        len=strlen(sub);
        int bg1=MinLex();//O index lexi small string started index
        printf("%d",bg1+1);
        bg1=MaxLex();    //0 index lexi large string started index
        printf(" %d\n",bg1+1);


    }
    return 0;
}
