//#pragma optimize O(3)

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 3e5 + 5;
int dp[MAXN][2] = {{-10000}};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> b(n), bq(n);
  vector<int> w(n), bw(n);
  for (auto &i : b) {
    cin >> i;
  }
  for (auto &i : w) {
    cin >> i;
  }
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      bq[i] = b[i];
    } else
      bq[i] = bq[i - 1] + b[i];
  }
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      bw[i] = w[i];
    } else
      bw[i] = bw[i - 1] + w[i];
  }

  vector<pair<int, pair<int, int>>> info(n);
  for (int i = 1; i <= m; i++) {
    int q, w, e, r;
    cin >> q >> w >> e >> r;
    info[w - 1] = {q, {e - 1, r}};
  }
  for (int i = 0; i < n; i++) {
    dp[i][0] = max(dp[i][0], (i ? dp[i - 1][0] : 0) + b[i]);
    dp[i][0] = max(dp[i][0], (i ? dp[i - 1][1] : 0) + b[i]);
    dp[i][1] = max(dp[i][1], (i ? dp[i - 1][0] : 0) + w[i]);
    dp[i][1] = max(dp[i][1], (i ? dp[i - 1][1] : 0) + w[i]);
    if (info[i].first == 1) {
      dp[info[i].second.first][0] =
          max(dp[info[i].second.first][0],
              (i ? dp[i - 1][0] : 0) + info[i].second.second +
                  b[info[i].second.first] - (i ? b[i - 1] : 0));
      dp[info[i].second.first][0] =
          max(dp[info[i].second.first][0],
              (i ? dp[i - 1][1] : 0) + info[i].second.second +
                  b[info[i].second.first] - (i ? b[i - 1] : 0));
    } else if (info[i].first == 2) {
      dp[info[i].second.first][1] =
          max(dp[info[i].second.first][1],
              (i ? dp[i - 1][0] : 0) + info[i].second.second +
                  w[info[i].second.first] - (i ? w[i - 1] : 0));
      dp[info[i].second.first][1] =
          max(dp[info[i].second.first][1],
              (i ? dp[i - 1][1] : 0) + info[i].second.second +
                  w[info[i].second.first] - (i ? w[i - 1] : 0));
    }
  }
  cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
}