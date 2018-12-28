#include <bits/stdc++.h>
using namespace std;
long long dp[5][100005];
long long cost[100005];
int main(){
    int n;
	cin>>n;
    string s;
    cin>>s;
    for (int i=0;i<n;i++)cin>>cost[i];
    for (int i=0;i<n;i++){
        if (s[i]=='h')dp[0][i+1]=dp[0][i]+cost[i];
        else dp[0][i+1]=dp[0][i];
    }
    for (int i=0;i<n;i++){
        if (s[i]=='a')dp[1][i+1]=min(dp[1][i]+cost[i],dp[0][i]);
        else dp[1][i+1]=dp[1][i];
    }
    for (int i=0;i<n;i++){
        if (s[i]=='r')dp[2][i+1]=min(dp[2][i]+cost[i],dp[1][i]);
        else dp[2][i+1]=dp[2][i];
    }
    for (int i=0;i<n;i++){
        if (s[i]=='d')dp[3][i+1]=min(dp[3][i]+cost[i],dp[2][i]);
        else dp[3][i+1]=dp[3][i];
    }
    long long ans=1ll<<60;
    for (int i=0;i<4;i++)ans=min(ans,dp[i][n]);
    cout<<ans<<endl;    
}