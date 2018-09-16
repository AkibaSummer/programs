#include <bits/stdc++.h>
using namespace std;
struct d{
    bool flag;
    long long max,min;
}dp[1005][6];
long long input[1005];
inline long long calc(long long &a,char &b,long long &c){
    if (b=='+')return a+c;
    else if (b=='-')return a-c;
    else if (b=='*')return a*c;
    else if (b=='/')return a/c;
}
int main(){
    int t;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    long long n,m,k;
    while (t--){
        cin>>n>>m>>k;
        for (int i=1;i<=n;i++){
            cin>>input[i];
        }
        string s;
        cin>>s;
        dp[0][0].max=dp[0][0].min=k;
        dp[0][0].flag=1;
        
        for (int i=1;i<=n;i++){
            for (int j=0;j<=m;j++){
                if (dp[i-1][j].flag){
                    dp[i][j].max=dp[i-1][j].max;
                    dp[i][j].min=dp[i-1][j].min;
                    dp[i][j].flag=1;
                }
                else {
                    dp[i][j].max=-(1ll<<60);
                    dp[i][j].min=1ll<<60;
                }
                if (!j)continue;
                if (dp[i-1][j-1].flag){
                    dp[i][j].max=max(calc(dp[i-1][j-1].max,s[j-1],input[i]),dp[i][j].max);
                    dp[i][j].max=max(calc(dp[i-1][j-1].min,s[j-1],input[i]),dp[i][j].max);
                    dp[i][j].min=min(calc(dp[i-1][j-1].max,s[j-1],input[i]),dp[i][j].min);
                    dp[i][j].min=min(calc(dp[i-1][j-1].min,s[j-1],input[i]),dp[i][j].min);
                    dp[i][j].flag=1;
                    
                }
            }
        }
        long long ans=-(1ll<<60);
        for (int i=1;i<=n;i++){
            
            ans=max(ans,dp[i][m].max);
        }
        cout<<ans<<endl;
    }
}