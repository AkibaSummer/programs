#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n, r;
    cin >> n >> r;
    if (n <= r) {
      cout << (n * (n - 1)) / 2 + 1 << endl;
    } else {
      cout << r * (r + 1) / 2 << endl;
    }
  }
}