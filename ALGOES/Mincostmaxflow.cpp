#include<bits/stdc++.h>
using namespace std;
 
#define MX  105
#define MOD 1000000007
#define inf 100000000
/// ==========================================////
 
int head[MX+10],par[MX+10],dis[MX+10];
bool chk[MX+10];
 
struct Edge
{
    int u,v,cap,cost,next;
    Edge() {}
    Edge(int a,int b,int c,int d,int e)
    {
        u=a,v=b,cap=c,cost=d,next=e;
    }
};
 
Edge edge[2*MX*MX];
int NE;
 
void init(int n)
{
    for(int i=0; i<=n; i++) head[i]=-1;
    NE=0;
}
 
void addEdge(int u,int v,int cap,int cost)
{
    edge[NE]=Edge(u,v,cap,cost,head[u]);
    head[u]=NE++;
    edge[NE]=Edge(v,u,0,-cost,head[v]);
    head[v]=NE++;
}
 
int spfa(int src,int sink,int tot)
{
    queue<int>Q;
    for(int i=0; i<=tot; i++) par[i]=-1,chk[i]=false,dis[i]=inf;
    Q.push(src);
    dis[src]=0;
    chk[src]=true;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        chk[u]=false;
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].v;
            int w=edge[i].cost;
            if(edge[i].cap>0 && dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                par[v]=i;
                if(!chk[v])
                {
                    chk[v]=true;
                    Q.push(v);
                }
            }
        }
    }
    if(par[sink]==-1) return 0;
    int cap=inf;
    for(int i=par[sink]; i!=-1; i=par[edge[i].u]) cap=min(cap,edge[i].cap);
    for(int i=par[sink]; i!=-1; i=par[edge[i].u]) edge[i].cap-=cap,edge[i^1].cap+=cap;
    return cap;
}
 
pair<int,int> min_cost_flow(int src,int sink,int tot)
{
    int ret=0,flow=0;
    while(true)
    {
        int cap=spfa(src,sink,tot);
 
        if(cap==0) break;
        flow+=cap;
        ret+=(cap*dis[sink]);
    }
    return make_pair(flow,ret);
}
 
 
int main()
{
    int t;
    cin>>t;
 
    for(int cs=1; cs<=t; cs++)
    {
        int n,m,p;
        cin>>n>>m>>p;
 
        init(n+4);// Clear
 
        int src=0,des=(n+1);
 
        for(int i=1; i<=m; i++)
        {
            int u,v,w,c;
            cin>>u>>v;
 
            cin>>c>>w;
            addEdge(u,v,c,w);
            addEdge(v,u,c,w);
        }
        addEdge(0,1,p,0);
        addEdge(n,n+1,p,0);
        pair<int,int> ans=min_cost_flow(src,des,des);
 
        printf("Case %d: ",cs);
        if(ans.first<p)
        {
            printf("impossible\n");
        }
        else
        {
            printf("%d\n",ans.second);
        }
    }
 
    return 0;
}
