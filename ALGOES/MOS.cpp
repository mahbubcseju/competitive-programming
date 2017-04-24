#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<b; i++)
#define LL long long
#define MX  2000007


int ar[100005];
int dp[100005];

struct z {
    int st,ed,id,sq;
    bool operator<(const z &p) const {
        if(sq<p.sq)     return true;
        else if(sq==p.sq) {
            if(ed<p.ed) return true;
            else if(ed==p.ed)   return (st<p.st);
        }
        return false;
    }
};

z a[100005];

LL Ans;

int n,m,k,F[MX];
LL ans[MX];

void Add(int num) {
    Ans+=F[ num^k ];
    F[num]++;
    return;
}

void Sub(int num) {
    F[num]--;
    Ans-=F[ num^k ];
}

int main() {
    cin>>n>>m>>k;

    for(int i=1; i<=n; i++) cin>>ar[i],dp[i]=(dp[i-1]^ar[i]);
    int sq=sqrt(n);

    F(i,1,m+1) {
        cin>>a[i].st>>a[i].ed;
        a[i].st--;// Need for problem not for algo
        a[i].sq=( a[i].st /sq)+(a[i].st%sq!=0);
        a[i].id=i;
    }

    sort(a+1,a+m+1);
    int left=0,right=0;
    F(i,1,m+1) {
        int L=a[i].st,R=a[i].ed;
        while(left<L) {
            Sub(dp[left]);
            left++;
        }
        while(left>L) {
            Add(dp[left-1]);
            left--;
        }
        while(right<=R) {
            Add(dp[right]);
            right++;
        }
        while(right-1>R) {
            Sub(dp[right-1]);
            right--;
        }
        ans[ a[i].id ]=Ans;
    }

    F(i,1,m+1) {
        printf("%lld\n",ans[i]);
    }


    return 0;
}
