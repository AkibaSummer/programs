#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

vector<int> vec;

void ins(int num, int s, int now) {
  if (num == 0) {
    vec.push_back(now);
    return;
  }
  for (int i = s; i <= 16 - num; i++) {
    ins(num - 1, i + 1, now | (1 << i));
  }
}

void solve() {
  int n;
  cin >> n;
  vector<int> input(n);
  for (auto &i : input) {
    cin >> i;
  }
  if (n <= (1 << 13)) {
    int ans = 256;
    for (auto &i : input) {
      for (auto &j : input) {
        int dist = __builtin_popcount(i xor j);
        if (dist) ans = min(ans, dist);
      }
    }
    cout << ans << endl;
  } else {
    vector<bool> judge(1 << 16);
    for (auto &i : input) judge[i] = true;
    int ans = 256;
    for (auto &i : vec) {
      for (auto &j : input) {
        if (judge[i ^ j]) {
          cout << __builtin_popcount(i) << endl;
          return;
        }
      }
    }
  }
}
int main() {
  vec.reserve(700);
  ins(1, 0, 0);
  ins(2, 0, 0);
  ins(3, 0, 0);
  // cout << vec.size() << endl;
  // for (auto &i : vec) cout << hex << i << endl;
  solve();
}