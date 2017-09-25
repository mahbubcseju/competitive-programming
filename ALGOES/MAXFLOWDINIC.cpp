/*http://acm.hdu.edu.cn/showproblem.php?pid=5093
*/
#include<bits/stdc++.h>

using namespace std;

#define in(a,x,y) (a>=x && a<=y)
#define out(a,x,y) (!in(a,x,y))
#define sz(a) ((int)a.size())
#define repv(i,a) for(int i=0;i<sz(a);i++)
#define revv(i,a) for(int i=sz(a)-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define pb push_back

#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)|(b))
#define XOR(a,b) ((a) ^ (b))
#define xx first
#define yy second
#define mp make_pair
#define sqr(x) ((x)*(x))
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
#define pi acos(-1.0)
#define eps  1e-12
#define MX   (lmt + 20 )
#define inf  1000000000
#define MOD  1000000007LL
//---------->0123456789123465789
#define lmt  100000
int INF = 1500000001 ;
struct dinic_maxflow
{

    struct edge
    {
        int a, b, cap, flow ;
        edge(int _a, int _b, int _c, int _d)
        {
            a = _a, b = _b, cap = _c, flow = _d;
        }
    } ;


    int n, s, t, d [ 30001 ] , ptr [ 30001 ] , q [ 30001 * 10 ] ;
    vector < edge > e ;
    vector < int > g [ 30001 ] ;

    void add_edge ( int a, int b, int cap )
    {
        edge e1 = edge( a, b, cap, 0 ) ;
        edge e2 = edge( b, a, 0 , 0 ) ;
        g [ a ] . push_back ( ( int ) e. size ( ) ) ;
        e. push_back ( e1 ) ;
        g [ b ] . push_back ( ( int ) e. size ( ) ) ;
        e. push_back ( e2 ) ;
    }

    bool bfs ( )
    {
        int qh = 0 , qt = 0 ;
        q [ qt ++ ] = s ;
        memset ( d, -1 , sizeof d ) ;
        d [ s ] = 0 ;
        while ( qh < qt && d [ t ] == - 1 )
        {
            int v = q [ qh ++ ] ;
            for ( size_t i = 0 ; i < g [ v ] . size ( ) ; ++ i )
            {
                int id = g [ v ] [ i ] ,
                    to = e [ id ] . b ;
                if ( d [ to ] == - 1 && e [ id ] . flow < e [ id ] . cap )
                {
                    q [ qt ++ ] = to ;
                    d [ to ] = d [ v ] + 1 ;
                }
            }
        }
        return d [ t ] != - 1 ;
    }

    int dfs ( int v, int flow )
    {
        if ( ! flow )  return 0 ;
        if ( v == t )  return flow ;
        for ( ; ptr [ v ] < ( int ) g [ v ] . size ( ) ; ++ ptr [ v ] )
        {
            int id = g [ v ] [ ptr [ v ] ] ,
                to = e [ id ] . b ;
            if ( d [ to ] != d [ v ] + 1 )  continue ;
            int pushed = dfs ( to, min ( flow, e [ id ] . cap - e [ id ] . flow ) ) ;
            if ( pushed )
            {
                e [ id ] . flow += pushed ;
                e [ id ^ 1 ] . flow -= pushed ;
                return pushed ;
            }
        }
        return 0 ;
    }

    int dinic ( )
    {
        int flow = 0 ;
        for ( ;; )
        {
            if ( !bfs () )  break ;
            memset ( ptr, 0 , sizeof ptr ) ;
            while ( int pushed = dfs ( s, INF ) )
            {
                flow += pushed ;
                if(pushed == 0)break;
            }
        }
        return flow ;
    }

    dinic_maxflow( int _n, int _s, int _t )
    {
        n = _n;
        s = _s;
        t = _t;
    }
};

int row[55][55];
int col[55][55];

char s[55][55];
int main()
{
    int ts , n , m ;
    scanf("%d", &ts);
    while(ts--)
    {
        scanf("%d%d", &n, &m);
        rep(i, 1, n)
        {
            scanf("%s", s[i] + 1);
        }
        memset(row , 0 , sizeof row);
        int cnt = 0;
        rep(i, 1, n)
        {
            cnt++;
            rep(j, 1, m)
            {
                if(s[i][j] == '#') cnt++;
                if(s[i][j] == '*')
                {
                    row[i][j] = cnt;
                }
            }
        }
        int r = cnt;
        memset(col , 0 , sizeof col);
        rep(j, 1, m)
        {
            cnt++;
            rep(i, 1, n)
            {
                if(s[i][j] == '#') cnt++;
                if(s[i][j] == '*')
                {
                    col[i][j] = cnt;
                }
            }
        }
        int c = cnt;
        dinic_maxflow dm = dinic_maxflow(cnt + 2 , 0 , cnt + 1);//cnt+2=node number! 0 = start node !cnt+1=sink node;
        rep(i, 1, n)
        {
            rep(j, 1, m)
            {
                if(row[i][j] == 0) continue;
                dm.add_edge(row[i][j] , col[i][j], 1);
                dm.add_edge(col[i][j],  row[i][j], 0);
            }
        }
        rep(i, 1, r)
        {
            dm.add_edge(0, i, 1);
        }
        rep(i, r + 1, c)
        {
            dm.add_edge(i, cnt + 1, 1);
        }
        int ans = dm.dinic();
        printf("%d\n", ans);
    }
    return 0;
}
