#include<bits/stdc++.h>
using namespace std;
vector<int >a[5001],cost[5001];
int n,m;
int INF=1000000000;

struct edge
{
    int u,w;
    edge() {};
    edge(int _a,int _b)
    {
        u=_a,w=_b;
    }
    bool operator<(const edge& p)const
    {
        return w>p.w;
    }

};
int dis(int s)
{
    priority_queue<edge>q;
    int s1[n+1];
    int s2[n+1];
    for(int i=1; i<=n; i++)
    {
        s1[i]=INF;
        s2[i]=INF;
    }
    q.push(edge(s,0));
    while(!q.empty())
    {
        edge df=q.top();
        q.pop();
        int co=df.w;
        int f=df.u;
        for(int i=0; i<a[f].size(); i++)
        {
            int y=a[f][i];
            if(f==y)
            {
                s1[y]=co;
                if(s1[f]+cost[f][i]<s2[f])
                {
                    s2[f]=s1[f]+cost[f][i];
                    q.push(edge(y,s1[y]));
                }

            }

            else    if(co+cost[f][i]<s1[y])
            {
                s2[y]=min(s1[y],s2[f]+cost[f][i]);
                s1[y]=co+cost[f][i];
                q.push(edge(y,s1[y]));
            }
            else if(co+cost[f][i]<s2[y]&&co+cost[f][i]>s1[y])
            {

                s2[y]=co+cost[f][i];
                q.push(edge(y,s1[y]));
            }
            else if(s2[f]+cost[f][i]<s2[y])
            {

                s2[y]=s2[f]+cost[f][i];
                q.push(edge(y,s1[y]));

            }
        }
    }
    return s2[n];
}

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++)
    {

        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++)
        {
            int u1,v1,w1;
            scanf("%d%d%d",&u1,&v1,&w1);
            a[u1].push_back(v1);
            a[v1].push_back(u1);
            cost[u1].push_back(w1);
            cost[v1].push_back(w1);

        }
        printf("Case %d: %d\n",t,dis(1));

        for(int i=1; i<=n; i++)
        {
            a[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}

