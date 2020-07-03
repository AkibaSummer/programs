#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (k % n == 0) {
      int need = k / n;
      cout << 0 << endl;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if ((i - j + n) % n < need)
            cout << 1;

          else
            cout << 0;
        }
        cout << endl;
      }
    } else {
      cout << 2 << endl;
      int need = k / n + 1;
      int shengyu = n - k % n;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if ((i - j + n) % n < need) {
            if (i == j && i < shengyu)
              cout << 0;
            else
              cout << 1;
          } else
            cout << 0;
        }
        cout << endl;
      }
    }
  }
}