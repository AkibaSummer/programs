#pragma GCC optimize(3)
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

signed main() {
  int n, m, t;
  cin >> n >> m >> t;
  vector<pair<int, int>> zhong(n), wan(m);
  int maxzhong = 0, maxwan = 0;
  for (auto &i : zhong) {
    cin >> i.second >> i.first;
    maxzhong = max(maxzhong, i.first);
  }
  for (auto &i : wan) {
    cin >> i.second >> i.first;
    maxwan = max(maxwan, i.first);
  }
  if (maxzhong + maxwan < t) {
    cout << -1 << endl;
    return 0;
  }
  zhong.push_back({0, 0});
  wan.push_back({0, 0});
  sort(zhong.begin(), zhong.end());
  sort(wan.begin(), wan.end());
  vector<int> minn(m + 1);
  minn[m] = wan[m].second;
  for (int i = m - 1; i >= 0; i--) {
    minn[i] = min(wan[i].second, minn[i + 1]);
  }
  int ans = 0x3fffffff;
  for (auto &i : zhong) {
    int need = t - i.first;
    auto pos = lower_bound(wan.begin(), wan.end(), pair<int, int>(need, 0)) -
               wan.begin();
    if (pos == m + 1) continue;
    ans = min(ans, i.second + minn[pos]);
  }
  cout << ans << endl;
}