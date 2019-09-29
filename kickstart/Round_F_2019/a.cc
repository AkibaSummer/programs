#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

void slove() {
  int n, k;
  cin >> n >> k;
  vector<int> input(n), tmp;
  for (auto &i : input) cin >> i;
  tmp = input;
  sort(tmp.begin(), tmp.end());
  tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
  int maxnum = -1;
  for (auto &i : input) {
    i = lower_bound(tmp.begin(), tmp.end(), i) - tmp.begin();
    maxnum = max(i, maxnum);
  }
  vector<vector<vector<int>>> dp(
      n, vector<vector<int>>(
             maxnum+1,
             vector<int>(n + 1,
                         n + 5)));  // dijige shishenme biandongjici chaduoshao

  for (int i = 0; i <= maxnum; i++) {
    dp[0][i][i != input[0]] = 0;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= maxnum; j++) {
      for (int k = 0; k < n; k++) {
        dp[i][j][k + 1] = min(dp[i - 1][j][k], dp[i][j][k + 1]);
        dp[i][input[i]][k] =
            min(dp[i - 1][j][k] + (input[i] != j), dp[i][input[i]][k]);
      }
    }
  }
  for (int j = 0; j < n; j++) {
    for (int i = 0; i <= maxnum; i++) {
      if (dp[n - 1][i][j] <= k) {
        cout << j << endl;
        return;
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    slove();
  }
}