#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

void slove() {
  int n;
  cin>>n;
  vector<int> input(n+1,-1);
  for (int i=0;i<n;i++){
    cin>>input[i];
  }
  int maxx = -1;
  int ans = 0;
  for (int i=0;i<n;i++){
    if (input[i]>maxx&&input[i]>input[i+1]){
      ans++;
    }
    maxx=max(maxx,input[i]);
  }
  cout<<ans<<endl;
}
int main() {
  fast;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    slove();
  }
}