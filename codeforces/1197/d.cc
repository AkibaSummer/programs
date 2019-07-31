#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long ll;

ll dp[300005][15];

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<ll> input(n);
    for (auto &i:input){
        cin>>i;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            dp[i][j]=-(1ll<<60);
        }
    }
    long long ans = 0;
    dp[0][1]=input[0]-k;
    ans=max(ans,dp[0][11]=max(0ll,input[0]-k));
    for (int i=1;i<n;i++){
        if (m==1){
            ans=max(ans,dp[i][11]=max(0ll,dp[i-1][11]+input[i]-k));
        }
        else {
            for (int j=2;j<m;j++){
                ans=max(ans,dp[i][j]=max(dp[i][j],dp[i-1][j-1]+input[i]));
            }
            ans=max(ans,dp[i][0]=max(dp[i][0],dp[i-1][m-1]+input[i]));
            ans=max(ans,dp[i][1]=max(dp[i][1],input[i]-k));
            ans=max(ans,dp[i][1]=max(dp[i][1],dp[i-1][0]+input[i]-k));
        }
    }
    cout<<ans<<endl;
    // for (int i=0;i<n;i++){
    //     for (int j=0;j<m;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
}