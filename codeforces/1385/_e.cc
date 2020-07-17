#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> input1, input2;
  input1.reserve(m);
  input2.reserve(m);
  for (int i = 0; i < m; i++) {
    int c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    if (c1 == 0) {
      input1.push_back({c2, c3});
    } else
      input2.push_back({c2, c3});
  }
  vector< pair<vector<int>, vector<int>>> points(n+1);
  for (auto &i : input2) {
    points[i.first].second.push_back(i.second);
    points[i.second].first.push_back(i.first);
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}