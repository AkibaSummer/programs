#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

void slove() {
  int n, m;
  cin >> n >> m;
  vector<int> input(n);
  for (auto &i : input) cin >> i;
  int now = m;
  int ans = 0;
  for (auto &i : input) {
    if (i == now) {
      now--;
    } else if (i == m)
      now = m - 1;
    else {
      now = m;
    }
    if (now == 0) {
      ans++;
      now = m;
    }
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