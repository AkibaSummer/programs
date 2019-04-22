#include <bits/stdc++.h>
using namespace std;
int input[105];
int dp[105][105];//time eated
int temp[105];
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>input[i];
    }
    temp[1]=m;
    for (int i=2;i<=100;i++){
        temp[i]=temp[i-1]*2/3;
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            dp[i][j]=dp[i-1][j-1]+min(temp[j],input[i]);
            ans=max(ans,dp[i][j]);
        }
        for (int j=1;j<=i-2;j++){
            dp[i][j]=max(dp[i][j],min(temp[j],input[i])+dp[i-2][j]);
            ans=max(ans,dp[i][j]);
        }
        for (int j=1;j<=i-3;j++){
            dp[i][1]=max(dp[i][1],min(temp[1],input[i])+dp[i-3][j]);
            ans=max(ans,dp[i][1]);
        }
    }
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=i;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    cout<<ans<<endl;
}