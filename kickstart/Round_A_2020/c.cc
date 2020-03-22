#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

void slove() {
  int n, k;
  cin >> n >> k;
  vector<int> input(n);
  for (auto &i : input) {
    cin >> i;
  }
  vector<int> cha(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cha[i] = input[i + 1] - input[i];
  }
  // for (auto &i : cha) {
  //   cerr << i << ' ';
  // }
  int l = 1;
  int r = 1000000000;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    int cnt = 0;
    for (auto &i : cha) {
      cnt += (i - 1) / mid;
    }
    if (cnt <= k)
      r = mid;
    else
      l = mid;
  }
  int cnt = 0;
  for (auto &i : cha) {
    cnt += (i - 1) / l;
  }
  if (cnt <= k)
    cout << l << endl;
  else
    cout << r << endl;
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