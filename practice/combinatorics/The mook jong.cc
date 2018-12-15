#include<bits/stdc++.h>
using namespace std;
long long ans[100],dp[5];
int main(){
    ans[1]=1;
    long long temp;
    for (int i=1;i<=70;i++){
        temp=dp[1];
        dp[1]=dp[3]+1;
        dp[3]=dp[3]+dp[2];
        dp[2]=temp;
        ans[i]=dp[1]+dp[2]+dp[3];
    }
    long long orz;
    while (cin>>orz){
        cout<<ans[orz]<<endl;
    }
}