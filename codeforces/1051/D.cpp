#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long  dp[1005][4][2005];
int main(){
    int n,k;
    cin>>n>>k;
    dp[1][0][1]=1;
    dp[1][1][2]=1;
    dp[1][2][2]=1;
    dp[1][3][1]=1;
    for (int i=2;i<=1000;i++){
        for (int j=1;j<=2003;j++){
            dp[i][0][j]+=dp[i-1][1][j]+dp[i-1][2][j]+dp[i-1][3][j-1]+dp[i-1][0][j];
            dp[i][1][j]+=dp[i-1][0][j-1]+dp[i-1][3][j-1]+(j==1?0:dp[i-1][2][j-2])+dp[i-1][1][j];
            dp[i][2][j]+=dp[i-1][0][j-1]+dp[i-1][3][j-1]+(j==1?0:dp[i-1][1][j-2])+dp[i-1][2][j];
            dp[i][3][j]+=dp[i-1][1][j]+dp[i-1][2][j]+dp[i-1][0][j-1]+dp[i-1][3][j];
            dp[i][0][j]%=mod;
            dp[i][1][j]%=mod;
            dp[i][2][j]%=mod;
            dp[i][3][j]%=mod;
        }
    }
    cout<<(dp[n][0][k]+dp[n][1][k]+dp[n][2][k]+dp[n][3][k])%mod<<endl;
}