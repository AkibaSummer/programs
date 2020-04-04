#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

int dfs(vector<pair<pair<int, int>, char>> &input, vector<vector<int>> &links,
        int a) {
  for (auto &i : links[a]) {
    if (input[i].second == input[a].second) {
      return -1;
    } else if (input[i].second == 0) {
      input[i].second = 'C' + 'J' - input[a].second;
      if (dfs(input, links, i) == -1) return -1;
    }
  }
  return 0;
}

void slove() {
  int n;
  cin >> n;
  vector<pair<pair<int, int>, char>> input(n);
  for (int i = 0; i < n; i++) {
    cin >> input[i].first.first >> input[i].first.second;
  }
  vector<vector<int>> links(n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (max(input[i].first.first, input[j].first.first) <
          min(input[i].first.second, input[j].first.second)) {
        links[i].push_back(j);
        links[j].push_back(i);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (input[i].second == 0) {
      input[i].second = 'C';
      if (dfs(input, links, i) == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
      }
    }
  }
  for (auto &i : input) {
    cout << i.second;
  }
  cout << endl;
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