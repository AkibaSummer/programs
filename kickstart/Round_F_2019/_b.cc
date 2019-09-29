#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

void slove() {
  int n, s;
  cin >> n >> s;
  vector<pair<int, vector<int>>> input(n);
  for (auto &i : input) {
    cin >> i.first;
    i.second.resize(i.first);
    for (auto &j : i.second) cin >> j;
  }
  sort(input.begin(), input.end());
  int ans = n * (n - 1);
  vector<bitset<1001>> bitsets(n);
  for (int i = 0; i < n; i++) {
    for (auto &j : input[i].second) {
      bitsets[i].set(j);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (bitsets[i] == bitsets[j])
        ans -= 2;
      else if ((bitsets[i] & bitsets[j])==bitsets[i])
        ans -= 1;
    }
  }
  cout << ans << endl;
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
/*
2
4 100
4 80 90 100 5
1 90
1 80
3 80 90 100
3 30
4 10 11 12 13
4 10 11 12 13
5 25 26 27 28 29
*/