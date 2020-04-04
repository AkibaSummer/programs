#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

void slove() {
  string s;
  cin >> s;
  int now = '0';
  for (auto &i : s) {
    for (; now < i; now++) {
      cout << '(';
    }
    for (; now > i; now--) {
      cout << ')';
    }
    cout << i;
  }
  for (; now > '0'; now--) {
    cout << ')';
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