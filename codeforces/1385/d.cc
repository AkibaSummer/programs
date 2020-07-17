#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
int lowbit(int a) { return a & (-a); }
int getans(char c, int l, int r, string &s) {
  if (l == r) {
    return s[l] != c;
  }
  int len = r - l + 1;
  //   cout << l << ' ' << r << ' ' << len << endl;
  //   assert(len - lowbit(len) == 0);
  int cnt = 0;
  for (int i = l; i < l + len / 2; i++) {
    if (s[i] != c) cnt++;
  }
  int ans = cnt + getans(c + 1, l + len / 2, r, s);
  cnt = 0;
  for (int i = l + len / 2; i <= r; i++) {
    if (s[i] != c) cnt++;
  }
  ans = min(ans, cnt + getans(c + 1, l, l + len / 2 - 1, s));
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << getans('a', 0, n - 1, s) << endl;
  }
}