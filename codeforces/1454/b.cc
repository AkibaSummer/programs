#include <bits/stdc++.h>
using namespace std;
#define mpa map
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    mpa<int, vector<int>> maps;
    for (int i = 1; i <= n; i++) {
      int tmp;
      cin >> tmp;
      maps[tmp].push_back(i);
    }
    for (auto &i : maps) {
      if (i.second.size() == 1) {
        cout << i.second[0] << endl;
        goto nxt;
      }
    }
    cout << -1 << endl;
  nxt:;
  }
}