#include <bits/stdc++.h>
using namespace std;
long long dp[300005][3];//pos ismulti/endmulti 
int main(){
    long long n,x;
    cin>>n>>x;
    vector<long long> input(n);
    for (auto &i:input){
        cin>>i;
    }
    long long ans=max(0ll,dp[0][0]=input[0]);
    ans=max(ans,dp[0][1]=input[0]*x);
    dp[0][2]=input[0];
    for (int i=1;i<n;i++){
        ans=max(ans,        dp[i][0]=max(input[i],dp[i-1][0]+input[i]));
        ans=max(ans,dp[i][1]=max(input[i]*x,dp[i-1][0]+input[i]*x));
        ans=max(ans,dp[i][1]=max(dp[i][1],dp[i-1][1]+input[i]*x));
        ans=max(ans,dp[i][2]=max(dp[i-1][2]+input[i],dp[i-1][1]+input[i]));
    }
    cout<<ans<<endl;

}