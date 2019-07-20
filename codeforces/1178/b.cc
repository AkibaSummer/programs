#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

long long dp[1000005][3];

int main(){
    string s,s1;
    cin>>s;
    for (int i=1;i<s.length();i++){
        if (s[i]=='v'&&s[i-1]=='v'){
            dp[i][0]+=1;
            dp[i][2]+=dp[i-1][1];
        }
        if (s[i]=='o'){
            dp[i][1]+=dp[i-1][0];
        }
        dp[i][0]+=dp[i-1][0];
        dp[i][1]+=dp[i-1][1];
        dp[i][2]+=dp[i-1][2];
    }
    cout<<dp[s.length()-1][2]<<endl;
}