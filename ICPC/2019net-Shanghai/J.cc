#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define int long long
const int mod = 1000000007;
void slove() {
  int n;
  cin >> n;
  vector<int> input(n);
  int sum = 0, maxnum = -1;
  for (auto &i : input) {
    cin >> i;
    sum += i;
    maxnum = max(maxnum, i);
  }
  sort(input.begin(), input.end(), greater<int>());
  vector<vector<int>> dpp(maxnum / 2 + 2, vector<int>(maxnum + 2));
  vector<int> dp((sum + 1) / 2 + 2 * maxnum + 5);
  dp[0] = 1;
  int maxxdp = 0;
  for (auto &i : input) {
    for (int j = maxxdp; j >= 0; j--) {
      dp[j + i] += dp[j];
      dp[j + i] %= mod;
      if ((j + i) - (sum + 1) / 2 >= 0 &&
          (j + i) - (sum + 1) / 2 <= maxnum / 2 + 1) {
        dpp[(j + i) - (sum + 1) / 2][i] += dp[j];
        dpp[(j + i) - (sum + 1) / 2][i] %= mod;
      }
    }
    maxxdp = min(maxxdp + i, (sum + 1) / 2 + maxnum);
  }
  int ans = 0;
  if (sum % 2 == 0) {
    for (int i = 0; i < dpp.size(); i++) {
      for (int j = 2 * i; j < dpp[i].size(); j++) {
        ans += dpp[i][j];
        ans %= mod;
      }
    }
  } else {
    for (int i = 0; i < dpp.size(); i++) {
      for (int j = i * 2 + 1; j < dpp[i].size(); j++) {
        ans += dpp[i][j];
        ans %= mod;
      }
    }
  }
  cout << ans % mod << endl;
}

signed main() {
  fast;
  int t;
  cin >> t;
  while (t--) {
    slove();
  }
}