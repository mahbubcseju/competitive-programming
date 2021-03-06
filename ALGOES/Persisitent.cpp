/*
You are working for Macrohard company in data structures department. After failing your previous task about key insertion you were asked to write a new data structure that would be able to return quickly k-th order statistics in the array segment.
That is, given an array a[1 ... n] of different integer numbers, your program must answer a series of questions Q(i, j, k) in the form: "What would be the k-th number in a[i ... j] segment, if this segment was sorted?"
For example, consider the array a = (1, 5, 2, 6, 3, 7, 4). Let the question be Q(2, 5, 3). The segment a[2 ... 5] is (5, 2, 6, 3). If we sort this segment, we get (2, 3, 5, 6), the third number is 5, and therefore the answer to the question is 5.
Input
The first line of the input contains n — the size of the array, and m — the number of questions to answer (1 ≤ n ≤ 100000, 1 ≤ m ≤ 5000).
The second line contains n different integer numbers not exceeding 10^9 by their absolute values — the array for which the answers should be given.
The following m lines contain question descriptions, each description consists of three numbers: i, j, and k (1 ≤ i ≤ j ≤ n, 1 ≤ k ≤ j - i + 1) and represents the question Q(i, j, k).
SAMPLE INPUT
7 3

1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 3
Output
For each question output the answer to it — the k-th number in sorted
a[i ... j] segment.
SAMPLE OUTPUT
5
6
3
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
#define mk make_pair
using namespace std;
#define xx first
#define yy second
#define mx  100000

typedef pair<int , int >P;

struct node
{
    int cnt;
    node *l,*r;
    node()
    {
        cnt=0;
        l=r=NULL;

    }
};
node a[(mx*20)+3];
node *b[mx+3];
int avail;

node *update(node *no,int l,int r,int val)
{
    // cout<<no<<l<<r<<val<<endl;
    node *u=&a[++avail];
    if(no!=NULL)*u=*no;
    u->cnt++;
    if(l==r)
    {
        return u;
    }
    int mid=(l+r)/2;
    if(val<=mid)
        u->l=update(u->l,l,mid,val);
    else  u->r=update(u->r,mid+1,r,val);
    return u;

}
int query(node *le,node *ri,int l,int r,int pos)
{
    if(l==r)
        return l;
    int sum=0;
    if( ri->l!=NULL)sum=ri->l->cnt;
    if(le!=NULL&&le->l!=NULL)sum-=le->l->cnt;
    int mid=(l+r)/2;
    if(pos<=sum)
    {
        return query(le!=NULL?le->l:NULL,ri->l,l,mid,pos);
    }
    else return query(le!=NULL?le->r:NULL,ri->r,mid+1,r,pos-sum);


}
P ar[mx+2];
int br[mx+2];
int cr[mx+2];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1; i<=n; i++)
    {
        int x;
        scanf("%d",&ar[i].xx);

        ar[i].yy=i;
    }
    sort(ar+1,ar+n+1);
    ar[0].xx=ar[1].xx+1;
    for(int i=1; i<=n; i++)
    {
        if(ar[i].xx!=ar[i-1].xx)
        {
            br[ar[i].yy]=i;
            cr[i]=ar[i].xx;

        }
        else br[ar[i].yy]=br[ar[i-1].yy];
    }
    b[0]=NULL;
    for(int i=1; i<=n; i++)
    {
        b[i]=update(b[i-1],1,n,br[i]);//amra br[i] tomo index take 1 barabo
    }
    for(int i=1; i<=m; i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        int u=query(b[x-1],b[y],1,n,z);
        u=cr[u];
        printf("%d\n",u);
    }
    return 0;
}
