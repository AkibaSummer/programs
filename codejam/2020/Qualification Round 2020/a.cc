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
  cin >> n;
  vector<vector<int>> input(n, vector<int>(n));
  for (auto &i : input) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += input[i][i];
  }
  cout << ans << ' ';
  ans = 0;
  for (auto &i : input) {
    vector<int> cnt(n);
    for (auto &j : i) {
      cnt[j - 1]++;
      if (cnt[j - 1] > 1) {
        ans++;
        break;
      }
    }
  }
  cout << ans << ' ';
  ans = 0;
  for (int i = 0; i < n; i++) {
    vector<int> cnt(n);
    for (int j = 0; j < n; j++) {
      cnt[input[j][i] - 1]++;
      if (cnt[input[j][i] - 1] > 1) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
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