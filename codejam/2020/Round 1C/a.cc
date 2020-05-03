#pragma GCC optimize(3)
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

void slove() {
  int x, y;
  cin >> x >> y;
  string s;
  cin >> s;
  int ans = 1e9;
  if (x == 0 && y == 0) {
    cout << 0 << endl;
    return;
  }
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'N')
      y++;
    else if (s[i] == 'S')
      y--;
    else if (s[i] == 'E')
      x++;
    else if (s[i] == 'W')
      x--;
    if (abs(x) + abs(y) <= i + 1) {
      ans = min(ans, i + 1);
    }
    // cerr << x << ' ' << y << ' ' << i + 1 << endl;
  }
  if (ans == 1e9) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << ans << endl;
  }
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