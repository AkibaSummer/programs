#include<bits/stdc++.h>

using namespace std;

char maps[305][305];
int dp[305][305];

void slove(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>(maps[i]+1);
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (maps[i][j]=='.'){
                dp[i][j]=1;
                ans=1;
            }
            else dp[i][j]=0;
        }
    }
    for (int i=2;i<=n;i++){
        for (int j=2;j<=m;j++){
            if (maps[i][j]=='.'){
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                ans=max(ans,dp[i][j]);
            }
        }
    }
    cout<<ans*ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        slove();
    }
}