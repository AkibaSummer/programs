#pragma GCC optmize(fast)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long

vector<vector<int>> *global_links;
vector<pair<int, int>> *global_range;

pair<pair<int, int>, pair<int, int>> dfs(int node, int pre = -1) {
  vector<vector<int>> &links = *global_links;
  vector<pair<int, int>> &range = *global_range;
  pair<pair<int, int>, pair<int, int>> ret = {{range[node].first, 0},
                                              {range[node].second, 0}};
  for (auto &i : links[node]) {
    if (i != pre) {
      pair<pair<int, int>, pair<int, int>> tmp = dfs(i, node);
      ret.first.second +=
          max(abs(ret.first.first - tmp.first.first) + tmp.first.second,
              abs(ret.first.first - tmp.second.first) + tmp.second.second);
      ret.second.second +=
          max(abs(ret.second.first - tmp.first.first) + tmp.first.second,
              abs(ret.second.first - tmp.second.first) + tmp.second.second);
    }
  }

  return ret;
}

void slove() {
  int n;
  cin >> n;
  vector<vector<int>> links(n);
  vector<pair<int, int>> range(n);
  global_links = &links;
  global_range = &range;
  for (int i = 1; i < n; i++) {
    int q, w;
    cin >> q >> w;
    links[q - 1].push_back(w - 1);
    links[w - 1].push_back(q - 1);
  }
  for (int i = 0; i < n; i++) {
    cin >> range[i].first >> range[i].second;
  }
  pair<pair<int, int>, pair<int, int>> ans = dfs(1);
  cout << max(ans.first.second, ans.second.second) << endl;
}

signed main() {
  fast
  int t;
  cin >> t;
  while (t--) {
    slove();
  }
}