#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
bool solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> input(n);
  set<pair<int, int>> S;
  for (auto &i : input) {
    cin >> i.first >> i.second;
    S.insert(i);
  }
  vector<pair<int, int>> x(n), y(n);
  vector<bool> visited(n);
  for (int i = 0; i < n; i++) {
    x[i] = input[i];
    y[i].first = input[i].second;
    y[i].second = input[i].first;
  }
  sort(x.begin(), x.end(), greater<pair<int, int>>());
  sort(y.begin(), y.end(), greater<pair<int, int>>());
  int posx = 0, posy = 0;
  while (posx < n && posy < n) {
    int maxx = x[posx].first;
    int maxy = y[posy].first;
    if (S.count({maxx, maxy})) {
      return true;
    }
    while (posx < n &&
           (x[posx].first >= maxx || x[posx].second >= maxy)) {
      posx++;
    }
    while (posy < n &&
           (y[posy].first >= maxy || y[posy].second >= maxx)) {
      posy++;
    }
  }
  return false;
}
int main() {
  fast;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    if (solve()) {
      cout << "Alice" << endl;
    } else {
      cout << "Bob" << endl;
    }
  }
}