#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[1000010];

signed main(){
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    for (int i=4;i<=100005;i++){
        dp[i]=dp[i-1]+dp[i-3];
        dp[i]%=998244353ll;
    }
    int t;
    scanf("%lld",&t);
    while(t--){
        int n,x,y;
        scanf("%lld%lld%lld",&n,&x,&y);
        int type = 0;
        if (x==1)type++;
        if (y==n)type++;
        if (type==0)printf("%lld\n",dp[y-x-1]);
        else if (type==1)printf("%lld\n",dp[y-x]);
        else if (type==2)printf("%lld\n",dp[y-x+1]);
        // cin>>x;
        // cout<<dp[x]<<endl;
    }
}