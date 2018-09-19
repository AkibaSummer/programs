#include <bits/stdc++.h>
using namespace std;
int dp[8];
int re(string &s){
    int res=0;
    for (auto &i:s){
        if (i=='A')res=res|1;
        if (i=='B')res=res|2;
        if (i=='C')res=res|4;
        //cout<<i<<res<<' ';
    }
    return res;
}
int main(){
    int n,num;
    cin>>n;
    string s;
    for (int i=0;i<8;i++)dp[i]=1000000000;
    for (int i=1;i<=n;i++){
        cin>>num>>s;
        dp[re(s)]=min(num,dp[re(s)]);
    }
    // for (int i=0;i<=7;i++){
    //     cout<<dp[i]<<' ';
    // }
    // cout<<endl;
    dp[1]=min(dp[1],dp[3]);
    dp[1]=min(dp[1],dp[5]);
    dp[1]=min(dp[1],dp[7]);
    dp[2]=min(dp[2],dp[3]);
    dp[2]=min(dp[2],dp[6]);
    dp[2]=min(dp[2],dp[7]);
    dp[4]=min(dp[4],dp[5]);
    dp[4]=min(dp[4],dp[6]);
    dp[4]=min(dp[4],dp[7]);
    dp[3]=min(dp[1]+dp[2],dp[3]);
    dp[5]=min(dp[1]+dp[4],dp[5]);
    dp[6]=min(dp[2]+dp[4],dp[6]);
    dp[7]=min(dp[1]+dp[6],dp[7]);
    dp[7]=min(dp[2]+dp[5],dp[7]);
    dp[7]=min(dp[4]+dp[3],dp[7]);
    // for (int i=0;i<=7;i++){
    //     cout<<dp[i]<<' ';
    // }
    cout<<(dp[7]>=1000000000?-1:dp[7])<<endl;
    return 0;
}