#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
int judge(int len, vector<pair<int, int>> &data, int y, int maxtime) {
  if (maxtime >= y + y)
    return 1;
  auto i = lower_bound(data.begin(), data.end(), make_pair(maxtime - y, 1ll<<60));
  int nowtime = 0;
  while (i != data.end()) {
    nowtime = max(nowtime + len * i->second, i->first + len * i->second);
    if (nowtime > maxtime)
      return 0;
    i++;
  }
  return 1;
}

int getans(int len, vector<pair<int, int>> &data, int y) {
  int l = y + len, r = y + y, ret = 1ll << 60;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (judge(len, data, y, m)) {
      // cout<<endl<<len<<' '<<m<<"YES"<<endl;
      ret = min(m, ret);
      r = m - 1;
    } else {
      // cout<<endl<<len<<' '<<m<<"NO"<<endl;
      l = m + 1;
    }
  }
  return ret;
}

void slove(int n, int y) {
  vector<int> input(n);
  for (auto &i : input)
    cin >> i;
  sort(input.begin(), input.end(), greater<int>());
  input.erase(
      upper_bound(input.begin(), input.end(), input[0] - y, greater<int>()),
      input.end());
  int tmp = input[0] - y;
  for (auto &i : input)
    i -= tmp;
  reverse(input.begin(), input.end());
  vector<pair<int, int>> data;
  data.reserve(n);
  for (auto &i : input) {
    if (data.empty())
      data.push_back({i, 1});
    else if (i == data.back().first)
      data.back().second++;
    else
      data.push_back({i, 1});
  }

  // for (auto &i : data) {
  //   cout << i.first << ' ' << i.second << endl;
  // }

  for (int i = 1; i <= y; i++) {
    cout << getans(i, data, y) + tmp << " \n"[i == y];
  }
}

signed main() {
  // fast;
  int n, y;
  while (cin >> n >> y) {
    slove(n, y);
  }
}
