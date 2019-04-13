#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

long long dp[1005][1005];
void slove(){
    memset(dp,-1,sizeof(dp));
    int n,c1;
    cin>>n>>c1;
    vector<long long> a(n+1),b(n+1),c(n+1);
    for (int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    dp[0][0]=c1;
    for (int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]+c[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (dp[i-1][j]>0)
                dp[i][j]=max(dp[i][j],dp[i-1][j]+c[i]);
            if (min(dp[i-1][j-1],b[i])-a[i]>0)
                dp[i][j]=max(dp[i][j],min(dp[i-1][j-1],b[i])-a[i]+c[i]);
        }
    }
    for (int i=n;i>=0;i--){
        if (dp[n][i]>0){
            cout<<i<<endl;
            return ;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        slove();
    }
}