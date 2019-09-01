#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long

int error(int x = 1) { return error(x + 1); }

inline int lowbit(int x) {
  // cout << (x & (-x)) << endl;
  return x & (-x);
}
string ans;
int flag;

void getans(int a, int b) {
  if (a == 1 && b == 1) {
    return;
  } else if (a < 1 || b < 1) {
    flag = 0;
    return;
  } else if (a > b) {
    if ((a - b + 1) & 1) {
      flag = false;
    }
    a = (a - b + 1) / 2;
    getans(a, b);
    ans += 'B';
  } else {
    if ((b - a + 1) & 1) {
      flag = false;
    }
    b = (b - a + 1) / 2;
    getans(a, b);
    ans += 'A';
  }
}

void slove() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (c == a && b == d) {
    cout << "Yes" << endl;
    cout << endl;
    return;
  }
  if (a != b) {
    int u1 = c - b;
    int d1 = a - b;
    int u2 = a - d;
    int d2 = a - b;
    if (((1ll << 63) & (u1 ^ d1)) || ((1ll << 63) & (u2 ^ d2))) {
      puts("No");
      return;
    }
    u1 = abs(u1);
    u2 = abs(u2);
    d1 = abs(d1);
    d2 = abs(d2);
    if (u1 % d1 || u2 % d2) {
      puts("No");
      return;
    }
    ans.clear();
    flag = 1;
    getans(u1 / d1, u2 / d2);
    if (flag) {
      puts("Yes");
      cout << ans << endl;
    } else {
      puts("No");
    }

  } else {
    cout << "No" << endl;
    return;
  }
  // if (a < b) {
  //   if (c > a || d < b) {
  //     cout << "No" << endl;
  //     return;
  //   }
  //   int sub1 = b - a, sub2 = d - c, sub3 = sub2 / sub1;
  //   if ((a - c) % sub1 != 0 || sub2 % sub1 != 0 || (lowbit(sub3) - sub3 !=
  //   0)) {
  //     cout << "No" << endl;
  //     return;
  //   }
  //   // cout << "Yes" << endl;
  //   string ans;
  //   int l = (a - c) / sub1, r = (d - b) / sub1;
  //   for (int i = 0; (1ll << i) != sub3; i++) {
  //     if ((1ll << i) & r) {
  //       ans += "A";
  //       r -= (1ll << i) * sub1;
  //     } else {
  //       ans += "B";
  //       l -= (1ll << i) * sub1;
  //     }
  //   }
  //   // if (!(r == 0 & l == 0))
  //   //   error();

  //   if (!(r == 0 && l == 0)) {
  //     cout << "No" << endl;
  //     return;
  //   } else {
  //     cout << "Yes" << endl;
  //     cout << ans << endl;
  //   }
  //   return;
  // } else if (a > b) {
  //   if (c < a || d > b) {
  //     cout << "No" << endl;
  //     return;
  //   }
  //   int sub1 = a - b, sub2 = c - d, sub3 = sub2 / sub1;
  //   if ((c - a) % sub1 != 0 || sub2 % sub1 != 0 || (lowbit(sub3) - sub3 !=
  //   0)) {
  //     cout << "No" << endl;
  //     return;
  //   }
  //   // cout << "Yes" << endl;
  //   string ans;
  //   int l = (c - a) / sub1, r = (b - d) / sub1;
  //   for (int i = 0; (1ll << i) != sub3; i++) {
  //     if ((1ll << i) & r) {
  //       ans += "A";
  //       r -= (1ll << i) * sub1;
  //     } else {
  //       ans += "B";
  //       l -= (1ll << i) * sub1;
  //     }
  //   }
  //   if (!(r == 0 && l == 0)) {
  //     cout << "No" << endl;
  //     return;
  //   } else {
  //     cout << "Yes" << endl;
  //     cout << ans << endl;
  //   }
  //   return;
  // } else {
  //   cout << "No" << endl;
  //   return;
  // }
}

signed main() {
  // fast
  long long t;
  cin >> t;
  while (t--) {
    slove();
  }
}
// 3
// 0 1 2 3
// 0 1 0 1
// 0 1 -1 3
