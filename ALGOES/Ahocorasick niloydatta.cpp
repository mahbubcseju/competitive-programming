#include<bits/stdc++.h>
#define eps 1e-8
#define xx first
#define yy second
#define LL long long
#define inf 100000
#define pb push_back
#define vsort(v) sort(v.begin(),v.end())
#define pi acos(-1)
#define clr(a,b) memset(a,b,sizeof a)
#define bclr(a) memset(a,false,sizeof a)
#define pii pair<int,int>
#define pll pair<LL,LL>
#define MOD 1000000007
#define MP make_pair
#define MX 250005

using namespace std;

const int chr=26;
struct node
{
    int next[chr];
    node()
    {
        memset(next,-1,sizeof next);
    }
};
node tree[MX];
int suffix[MX],indx,len,path[MX];
int val[MX],ed[505];

struct Aho_Corasick
{
    void init()
    {
        len=0;
        memset(tree,0,sizeof tree);
        memset(suffix,0,sizeof suffix);
        memset(val,0,sizeof val);
        tree[0]=node();
        indx=0;
    }
    void insert(char *s,int pos)
    {
        int now=0;
        for(int i=0; s[i]!='\0'; i++)
        {
            int id=s[i]-'a';
            if(tree[now].next[id]==-1)
            {
                tree[now].next[id]=++indx;
                tree[indx]=node();
            }
            now=tree[now].next[id];
        }
        ed[pos]=now;
    }
    void reverse_link()
    {
        queue<int>Q;
        for(int i=0; i<chr; i++)
        {
            if(tree[0].next[i]!=-1)
            {
                Q.push(tree[0].next[i]);
            }
            else tree[0].next[i]=0;
        }
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            for(int i=0; i<chr; i++)
            {
              
                int v=tree[u].next[i];
                if(v==-1)
                {
                    tree[u].next[i]=tree[suffix[u]].next[i];
                    continue;
                }
                suffix[v]=tree[suffix[u]].next[i];
                Q.push(v);
                path[len++]=v;
            }
        }
    }
    void search(char *s)
    {
        int now=0;
        for(int i=0; s[i]!='\0'; i++)
        {
            int id=s[i]-'a';
            now=tree[now].next[id];
            val[now]++;
        }
        for(int i=len-1; i>=0; i--)
        {
            val[suffix[path[i]]]+=val[path[i]];
        }
    }
};
char s[555];
char t[1000006];
int main()
{
    int test;
    scanf("%d",&test);
    for(int kase=1; kase<=test; kase++)
    {
        Aho_Corasick AC;
        AC.init();
        int n;
        scanf("%d",&n);
        scanf("%s",t);
        for(int i=1; i<=n; i++)
        {
            scanf("%s",s);
            AC.insert(s,i);
        }
        AC.reverse_link();
        AC.search(t);
        printf("Case %d:\n",kase);
        for(int i=1; i<=n; i++)
        {
            printf("%d\n",val[ed[i]]);
        }
    }
    return 0;
}
