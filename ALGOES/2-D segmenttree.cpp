//Max MIn and Single point update Using 2-D segment tree!
#include<bits/stdc++.h>
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define PI(a) printf("%d\n",a)
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define x first
#define y second
using namespace std;
typedef pair<int,int> P;

////////define value/////
int n;
int a[504][504];
P ar[2004][2004];
void build_y(int nx,int sx,int ex,int ny,int sy,int ey) {
    if(sy==ey) {
        if(sx==ex) {
            ar[nx][ny].x=ar[nx][ny].y=a[sx][sy];

        } else
        {
            ar[nx][ny].x=max(ar[nx*2][ny].x,ar[nx*2+1][ny].x);
             ar[nx][ny].y=min(ar[nx*2][ny].y,ar[nx*2+1][ny].y);
        }
        return;
    }
    int mid=(sy+ey)>>1;
    build_y( nx, sx,ex,ny*2,sy,mid);
    build_y( nx, sx,ex,ny*2+1,mid+1,ey);
    ar[nx][ny].x=max(ar[nx][ny*2].x,ar[nx][ny*2+1].x);
    ar[nx][ny].y=min(ar[nx][ny*2].y,ar[nx][ny*2+1].y);
    //build_y(int nx,int sx,int ex,int ny,int sy,int ey)
}


void build_x(int no,int s,int e) {
    if(s!=e) {
        int mid=(s+e)>>1;
        build_x(no*2,s,mid);
        build_x(no*2+1,mid+1,e);
    }
    build_y(no,s,e,1,1,n);
}
void update_y(int no,int s,int e,int ny,int ys,int ye,int y) {
    if(ys==ye) {
        if(s==e) {
            ar[no][ny].x=ar[no][ny].y=a[s][ys];

        } else
        {


            ar[no][ny].x=max(ar[no*2][ny].x,ar[no*2+1][ny].x);
            ar[no][ny].y=min(ar[no*2][ny].y,ar[no*2+1][ny].y);

        }
        return;
    }
    int mid=(ys+ye)>>1;
    if(mid>=y)
        update_y( no, s,e,ny*2,ys,mid,y);

    else
        update_y( no, s,e,ny*2+1,mid+1,ye,y);
    ar[no][ny].x=max(ar[no][ny*2].x,ar[no][ny*2+1].x);
    ar[no][ny].y=min(ar[no][ny*2].y,ar[no][ny*2+1].y);

}
void update_x(int no,int s,int e,int x,int y) {
    if(s!=e) {
        int mid=(s+e)>>1;

        if(mid>=x)
            update_x(no*2,s,mid,x,y);
        else update_x(no*2+1,mid+1,e,x,y);
    }
    update_y(no,s,e,1,1,n,y);
}
P fuck(P x,P y)
{
    x.x=max(x.x,y.x);
    x.y=min(x.y,y.y);
    return x;
}
P query_y(int nx,int sx,int se,int ny,int ys,int ye,int qy1,int qy2)
{
    if(ys>=qy1&&ye<=qy2)
    {

        return ar[nx][ny];
    }
    int mid=(ys+ye)>>1;
    if(mid>=qy2)
    {
        return query_y(nx,sx,se,ny*2,ys,mid,qy1,qy2);

    }
    else if(mid<qy1)
    {
        return query_y(nx,sx,se,ny*2+1,mid+1,ye,qy1,qy2);
    }
    else
    {
        P xl=query_y(nx,sx,se,ny*2,ys,mid,qy1,mid);
        P yl=query_y(nx,sx,se,ny*2+1,mid+1,ye,mid+1,qy2);
        return fuck(xl,yl);
    }

}
P query_x(int nx,int sx,int se,int qx1,int qx2,int qy1,int qy2)
{
    if(sx>=qx1&&se<=qx2)
    {
       // cout<<sx<<se<<endl;
        return query_y(nx,sx,se,1,1,n,qy1,qy2);
    }
    int mid=(sx+se)>>1;
    if(mid>=qx2)return query_x(nx*2,sx,mid,qx1,qx2,qy1,qy2);
    else if(mid<qx1)return query_x(nx*2+1,mid+1,se,qx1,qx2,qy1,qy2);
    else
    {
         P xl=query_x(nx*2,sx,mid,qx1,mid,qy1,qy2);

         P yl=query_x(nx*2+1,mid+1,se,mid+1,qx2,qy1,qy2);
         return fuck(xl,yl);

    }
}
int main() {

    I(n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            I(a[i][j]);
        }
    }
    build_x(1,1,n);

    int q;
    I(q);
    while(q--) {
        char ch[2];
        SC("%s",ch);
        if(ch[0]=='c') {
            int x,y,z;
            I2(x,y);
            I(z);
            a[x][y]=z;
            update_x(1,1,n,x,y);
        } else {
            int u,v,x,y;
            I2(u,v);
            I2(x,y);
            P xl=query_x(1,1,n,u,x,v,y);
            PC("%d %d\n",xl.x,xl.y);
        }
    }


    return 0;
}
