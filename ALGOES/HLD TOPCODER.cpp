#include<bits/stdc++.h>
using namespace std;
const int V = 100000;
vector<int> adj[V];     // adjacency list
int parent[V], heavy[V];
int depth[V], size[V];
int chain[V], head[V];
//Where chain[u] is u's chain number and head[u]
// is the node closest to root in u's chain.

void DFS(int i)
{
    size[i] = 1;
    for (int k=0; k<adj[i].size(); ++k)
    {
        int j = adj[i][k];
        if (j == parent[i]) continue;

        parent[j] = i;
        depth[j] = depth[i] + 1;

        DFS(j);

        size[i] += size[j];
        if (heavy[i] == -1 || size[j] > size[heavy[i]])
            heavy[i] = j;
    }
}

void heavylight_DFS(int N)
{
    memset(heavy, -1, sizeof(heavy));

    parent[0] = -1;
    depth[0] = 0;
    DFS(0);

    int c = 0;
    for (int i=0; i<N; ++i)
        if (parent[i] == -1 || heavy[parent[i]] != i)
        {
            for (int k = i; k != -1; k = heavy[k])
                chain[k] = c, head[k] = i;
            c++;
        }
}

int q[V], *qf, *qb; // BFS queue  No need of above dfs
//qf queue er front address and qb queue er back adddress

void heavylight_BFS(int N)
{
    qf = qb = q; // Both qf and qr =  starting  address of q
    parent[0] = -1;
    depth[0] = 0;
    *qb++ = 0;//back adrres increase to 1 and queue 0 position a 0
    // insert so front address initial address
    while (qf < qb)
        for (int i=*qf++, k=0; k<adj[i].size(); ++k)
        {
            int j = adj[i][k];
            if (j == parent[i]) continue;
            parent[j] = i;
            depth[j] = depth[i] + 1;//Depth nirnoy kore
            *qb++ = j;// quue te push
        }

    memset(size, 0, sizeof(size));
    memset(heavy, -1, sizeof(heavy));
    for (int k=N-1; k>0; --k)
    {
        int j = q[k], i = parent[q[k]];
        size[j]++;//Nijer niche koto gola ache
        size[i] += size[j];//parent er niche koto gola ache
        if (heavy[i] == -1 || size[j] > size[heavy[i]])
            heavy[i] = j;
    }

    int c = 0;
    for (int i=0; i<N; ++i)
        if (parent[i] == -1 || heavy[parent[i]] != i)
        {
            for (int k = i; k != -1; k = heavy[k])
                chain[k] = c, head[k] = i;//chain creation  and  head of chain creation
            //segment tree er jonno array ekhan theke create korte hobe see anudheeps code for help
            c++;
        }
}

int lca_1(int i, int j)
{
    while (chain[i] != chain[j])
        if (depth[head[i]] > depth[head[j]])
            i = parent[head[i]];
        else
            j = parent[head[j]];

    return depth[i] < depth[j] ? i : j;
}
//Jekono ekta use korlei hobe
int lca_2(int i, int j)
{
    while (chain[i] != chain[j])
    {
        if (depth[head[i]] > depth[head[j]])
            swap(i, j);
        j = parent[head[j]];
    }

    if (depth[i] > depth[j])
        swap(i, j);
    return i;
}

void look_inside(int N)
{
    int i;

    printf("\n");
    printf("HEAVY: \n");
    printf("(i, j): i----(heavy edge)----j\n\n");

    for (i = 0; i < N; i++)
        printf("(%d, %d)\n", i, heavy[i]);

    printf("\n");
    printf("CHAIN: \n");
    printf("(i, j): Node i is in group (heavy-path group) number j\n\n");

    for (i = 0; i < N; i++)
        printf("(%d, %d)\n", i, chain[i]);

    printf("\n");
    printf("HEAD: \n");
    printf("(i, j): Node i goes up all the way to the highest node (j) which is in the same group\n\n");

    for (i = 0; i < N; i++)
        printf("(%d, %d)\n", i, head[i]);
}


int main()
{
    int N, i, j;

    cin>>N;

    for (i = 0; i < N; i++)
        adj[i].clear();
    for(int i=1; i<N; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    //heavylight_DFS(N);
    heavylight_BFS(N);

    //printf("%d\n", lca_2(12, 16));

    //printf("%d\n", lca_2(16, 12));

    //printf("%d\n", lca_2(0, 7));

    //printf("%d\n", lca_2(0, 24));

    printf("%d\n", lca_1(1, 2));

    //look_inside(N); //I just added it into this program in order to understand more about how it works
}
