#pragma GCC optimize(3)
#include <algorithm>
#include <cmath>
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
  int n;
  cin >> n;
  vector<int> input;
  input.reserve(n + 1);
  //    input.push_back(0);
  int sum = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    sum += tmp;
    input.push_back(sum);
  }
  map<int, int> cnt;
  vector<int> tt;
  tt.reserve(10000);
  for (int i = 0; i * i <= 10000000; i++) {
    tt.push_back(i * i);
  }
  cnt[0] = 1;
  for (auto &i : input) {
    for (auto &j : tt) {
      if (cnt.count(i - j)) {
        ans += cnt[i - j];
      }
    }
    cnt[i]++;
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