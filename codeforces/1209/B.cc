#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define endl "\n"
const int mod = 1000000007;

void slove() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<int, int>> input(n);
  for (auto &i : input)
    cin >> i.first >> i.second;
  vector<vector<int>> ison(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      ison[i].push_back(1);
    else
      ison[i].push_back(0);
  }
  // cerr << 1 << endl;
  for (int i = 0; i < 2000; i++) {
    for (int j = 0; j < n; j++) {
      // cout << i << ' ' << input[j].second << endl;
      if (i >= input[j].second && (i - input[j].second) % input[j].first == 0) {
        // cout << ison[j].back() << endl;
        ison[j].push_back(1 - ison[j].back());
      } else {
        // cout << j << ' ' << ison.size() << endl;
        ison[j].push_back(ison[j].back());
      }
    }
  }
  // cerr << 1 << endl;
  int ans = 0;
  for (int i = 0; i < 2000; i++) {
    int tmp = 0;
    for (int j = 0; j < n; j++) {
      tmp += ison[j][i];
    }
    ans = max(ans, tmp);
  }
  // cerr << 1 << endl;
  cout << ans << endl;
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