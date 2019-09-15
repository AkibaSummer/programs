#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)

const int mod = 1000000007;

void slove() {
  int n;
  cin >> n;
  vector<int> input(n), visited(n);
  for (auto &i : input)
    cin >> i;
  sort(input.begin(), input.end());
  int ans=0;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      ans++;
      for (int j = i; j < n; j++) {
        if (input[j]%input[i]==0){
          visited[j]=1;
        }
      }
    }
  }
  cout<<ans<<endl;
}

int main() {
  // fast;
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    slove();
  }
}