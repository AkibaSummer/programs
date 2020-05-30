#pragma GCC optimize(3)
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

void slove() {
  int n, m;
  cin >> n >> m;
  vector<string> input(n);
  for (auto &i : input) cin >> i;
  vector<char> output;
  set<char> all;
  for (auto &i : input) {
    for (auto &j : i) {
      all.insert(j);
    }
  }
  for (;;) {
    map<char, int> maps;
    for (auto &i : all) {
      maps[i] = 0;
    }
    if (maps.size() == 0) {
      break;
    }
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m; j++) {
        if (input[i + 1][j] != input[i][j] && all.count(input[i + 1][j]) &&
            all.count(input[i][j])) {
          maps[input[i][j]]++;
        }
      }
    }
    int flag = 0;
    for (auto &i : maps) {
      if (i.second == 0) {
        output.push_back(i.first);
        all.erase(i.first);
        flag = 1;
      }
    }
    if (flag == 0) {
      cout << -1 << endl;
      return;
    }
  }
  for (auto &i : output) cout << i;
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