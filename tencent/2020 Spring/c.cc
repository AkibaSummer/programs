#pragma GCC O(3)
#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  int ans = 100;
  int judge = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      judge = 1;
    }
  }
  for (int i = 1; i < (1 << n) - 1; i++) {
    vector<pair<int, pair<int, int>>> target(n);  // num ,state ,pos
    for (int j = 0; j < n; j++) {
      if ((1 << j) & i) {
        target[j] = {a[j], {0, j}};

      } else {
        target[j] = {b[j], {1, j}};
      }
    }
    sort(target.begin(), target.end());
    int tmp = 0;
    for (int j = 0; j < n; j++) {
      if (target[j].first == a[j]) {
        continue;
      } else if (target[j].second.first == 1) {
        tmp++;
      } else if (target[j].second.second != j) {
        tmp += 2;
      }
    }
    ans = min(ans, (tmp + 1) / 2);
  }
  cout << ans << endl;
}