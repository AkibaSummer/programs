#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long

signed main(){
  fast;
  int n,m;
  while(cin>>n>>m){
    vector<int> dp(m,1<<30);
    pair<int,int> ans = {1<<30,0};
    dp[0]=0;
    while(n--){
      int p,c;
      cin>>p>>c;
      for (int i=0;i<m;i++){
        if (i+c<m){
          dp[i+c]=min(dp[i+c],dp[i]+p);
        }
        else {
          if (dp[i]+p<ans.first){
            ans={dp[i]+p,i+c};
          }
          else if (dp[i]+p==ans.first){
            ans.second=max(ans.second,i+c);
          }
        }
      }
    }
    cout<<ans.first<<' '<<ans.second<<endl;
  }
  
}