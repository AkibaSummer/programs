#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

void slove() {
  map<int, pair<int, int>> possible;
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    possible[i * n] = {i, 0};
    for (int j = 1; j < n; j++) {
      possible[i * n - i - i + (i + j - 1) % n + 1 + (i - j + n - 1) % n + 1] =
          {i, j};
    }
  }
  if (possible.count(k) == 0) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << "POSSIBLE" << endl;
    vector<vector<int>> ans(n, vector<int>(n));
    auto tmp = possible[k];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ans[i][j] = (tmp.first - i + j + n - 1) % n + 1;
      }
    }
    swap(ans[0], ans[tmp.second]);
    for (auto &i : ans) {
      for (auto &j : i) {
        cout << j << ' ';
      }
      cout << endl;
    }
  }
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