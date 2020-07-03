#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    if (n + m > a + b) {
      cout << "No" << endl;
      continue;
    }
    if (m > min(a, b)) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
}