/*
A string is a finite sequence of symbols that are chosen from an alphabet. In this problem you
are given two non-empty strings A and B, both contain lower case English alphabets. You have to
find the number of times B occurs as a substring of A.
1
abc
abc
case 1: 1
*/

#include<bits/stdc++.h>
using namespace std;
string a,b;
int pat[1000006];
void pattern()
{
    int l=b.size();

    pat[0]=-1;
    int j=-1;
    for(int i=0; i<l; i++)
    {
        while(j!=-1&&b[j]!=b[i])
        {
            j=pat[j];
        }
        j++;
        pat[i+1]=j;

    }
}

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int i=1; i<=tc; i++)
    {
        cin>>a>>b;
        int sum=0;
        int l=a.size(),l1=b.size();
        pattern();
        int k=0;
        for(int  j=0; j<l; j++)
        {
            while(k!=-1&&b[k]!=a[j])
            {
                k=pat[k];
            }
            k++;
            if(k==l1)sum++;
        }
        printf("Case %d: %d\n",i,sum);
    }

    return 0;
}


