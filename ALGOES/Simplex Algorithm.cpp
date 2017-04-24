/*
http://college.cengage.com/mathematics/larson/elementary_linear/4e/shared/downloads/c09s3.pdf
https://people.richland.edu/james/ictcm/2006/simplex.html
For linear programming problems involving two variables, the graphical solution method
introduced in Section 9.2 is convenient. However, for problems involving more than two
variables or problems involving a large number of constraints, it is better to use solution
methods that are adaptable to computers. One such method is called the
simplex method,
developed by George Dantzig in 1946. It provides us with a systematic way of examining
the vertices of the feasible region to determine the optimal value of the objective function.
We introduce this method with an example.
Suppose we want to find the maximum value of (A[2]) p=40x1	+	30x2    where
subject to the following constraint

x1	+	x2	≤	16 A[0]
x1	+	x2	≤	9  A[1]
3x1	+	2x2	≤	24
x1	,	x2	≥	0

Since the left-hand side of each inequality
is less than or equal to the right-hand side, there
must exist nonnegative numbers  and  that can be added to the left side of each equa-
tion to produce the following system of linear equations

Maximize	P	=	40x1	+	30x2
Subject to:
x1	+	2x2	+	s1	 	 	 	 	=	16
x1	+	x2	 	 	+	s2	 	 	=	9
3x1	+	2x2	 	 	 	 	+	s3	=	24
x1	,	x2	,	s1	,	s2	,	s3	≥	0
*/
#include<bits/stdc++.h>
#define MX 200000
#define INF    100000000000000000
#define EPS    1e-9
#define SC scanf
#define PC printf
using namespace std;

double b[MX+ 7],A[3][MX + 7];
void Pivot(int m, int n, double A[3][MX + 7], int *B, int *N, int r, int c)
{
    int i,j;
    swap(N[c], B[r]);
    A[r][c] = 1.0 / A[r][c];
    for(j = 0; j <= n; j++)
    {
        if( j!=c ) A[r][j] *= A[r][c];
    }
    for(i = 0; i <= m; i++)
    {
        if(i != r)
        {
            for(j = 0; j <= n; j++)
            {
                if(j != c)
                {
                    A[i][j] -= A[i][c] * A[r][j];
                }
            }
            A[i][c] = -A[i][c] * A[r][c];
        }
    }
}

int Feasible(int m, int n, double A[3][MX+7], int *B, int *N)
{
    int r, c, i;
    double p, v;
    while (true)
    {
        for(p = INF, i = 0; i < m; i++)
        {
            if(A[i][n] < p)
            {
                p = A[r=i][n];
            }
        }
        if(p > -EPS)
        {
            return 1;
        }
        for(p = 0, i = 0; i < n; i++)
        {
            if(A[r][i] < p)
            {
                p = A[r][c=i];
            }
        }
        if(p > -EPS) return 0;
        p = A[r][n] / A[r][c];
        for(i = r + 1; i < m; i++)
        {
            if(A[i][c] > EPS)
            {
                v = A[i][n] / A[i][c];
                if(v < p)
                {
                    r = i;
                    p = v;
                }
            }
        }
        Pivot(m, n, A, B, N, r, c);
    }
}

int Simplex(int m, int n, double A[3][MX + 7], double *b, double &Ret)
{
    int B[MX+7], N[MX+7], r, c, i;
    double p, v;
    for(i = 0; i < n; i++)
    {
        N[i] = i;
    }
    for(i = 0; i < m; i++)
    {
        B[i] = n + i;
    }
    if (!Feasible(m, n, A, B, N))
    {
        return 0;
    }
    while (true)
    {
        for(p = 0, i = 0; i < n; i++)
        {
            if(A[m][i] > p)
            {
                p = A[m][c=i];
            }
        }
        if(p < EPS)
        {
            for(i = 0; i < n; i++)
            {
                if(N[i] < n)
                {
                    b[N[i]] = 0;
                }
            }
            for(i = 0; i < m; i++)
            {
                if(B[i] < n)
                {
                    b[B[i]] = A[i][n];
                }
            }
            Ret = -A[m][n];
            return 1;
        }
        for( p=INF,i=0; i<m; i++ )
        {
            if(A[i][c] > EPS)
            {
                v = A[i][n] / A[i][c];
                if(v < p)
                {
                    p = v;
                    r = i;
                }
            }
        }
        if(p == INF)
        {
            return -1;
        }
        Pivot(m, n, A, B, N, r, c);
    }
}
int main()
{
    int n;
    cin>>n;
    double p,q,ret;
    cin>>p>>q;
    for(int i=0;i<n;i++)
    {
        SC("%lf%lf",&A[0][i],&A[1][i]);
        A[0][i]*=-1.0;
        A[1][i]*=-1.0;
        A[2][i]=-1.0;//This this equation which is tobe maximized
    }
    A[0][n]=-p;
    A[1][n]=-q;
    A[2][n]=0.0;
    Simplex(2,n,A,b,ret);
    double ans=0.0;
    for(int i=0;i<n;i++)ans+=b[i];
    PC("%.8lf\n",ans);
    return 0;
}







