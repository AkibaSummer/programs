#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> input(n);
    int minn = 0x3fffffff;
    int maxn = 0;
    for (auto &i : input) {
      cin >> i;
      minn = min(minn, i);
      maxn = max(maxn, i);
    }
    int ans = 0;
    for (auto &i : input) {
      ans += max(0, (i - 1) / (2 * minn - 1));
    }
    cout << ans << endl;
  }
}