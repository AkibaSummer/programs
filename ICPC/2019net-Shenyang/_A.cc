#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)

typedef vector<__int128> vec;
typedef vector<vec> mat;
const long long mod = 1025436931;

// void print(mat &a) {
//   for (int i = 0; i < a.size(); i++) {
//     for (int j = 0; j < a.size(); j++) {
//       printf("%lld ", a[i][j]);
//     }
//     printf("\n");
//   }
// }

#define int __int128

void mul(mat &a, mat &b, mat &c) {
  if (c.size() != a.size()) {
    c = std::move(vector<vec>(a.size(), vec(a.size(), 0)));
  }
  // puts("here");
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a.size(); j++) {
      c[i][j] = 0;
      for (int k = 0; k < a.size(); k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
      c[i][j] %= mod;
    }
  }
}

void mul(mat &a, vec &b) {
  int t0 = b[0], t1 = b[1];
  b[0] = (t0 * a[0][0] + t1 * a[0][1]) % mod;
  b[1] = (t0 * a[1][0] + t1 * a[1][1]) % mod;
}

mat fib[3][100050];

#undef int 
#define int long long

int fbnq(int n) {
  n++;
  vec b;
  b.push_back(0);
  b.push_back(1);
  mul(fib[0][n % 100000], b);
  // printf("%lld\n",b[1]);
  mul(fib[1][n / 100000], b);
  return b[1];
}


void slove() {
  int n, m, x1, x2, y1, y2;
  cin >> n >> m >> x1 >> y1 >> x2 >> y2;
  if (n == 1 && m == 1) {
    puts("1");
    return;
  }
  if (n >= 2 && m >= 2 && ((x1 + y1) % 2 != (x2 + y2) % 2)) {
    puts("countless");
    return;
  } else {
    int num = 0;
    if (x1 == x2) {
      num += max(x1 - 1, n - x1);
    } else if (x2 < x1) {
      num += x1 - 1;
    } else {
      num += n - x1;
    }
    if (y1 == y2) {
      num += max(y1 - 1, m - y1);
    } else if (y2 < y1) {
      num += y1 - 1;
    } else {
      num += m - y1;
    }
    num--;
    if ((n == 1 || m == 1) && ((x1 + y1) % 2 != (x2 + y2) % 2)) {
      num++;
    }
    // }
    cout << (fbnq(num + 2) - 1 + mod) % mod << endl;
  }
}

signed main() {
  // fast;

  fib[0][0] = vector<vec>(2, vec(2, 0));
  fib[0][1] = vector<vec>(2, vec(2, 0));

  fib[0][0][0][0] = 1;
  fib[0][0][0][1] = 0;
  fib[0][0][1][0] = 0;
  fib[0][0][1][1] = 1;
  fib[0][1][0][0] = 1;
  fib[0][1][0][1] = 1;
  fib[0][1][1][0] = 1;
  fib[0][1][1][1] = 0;

  for (int i = 2; i <= 100000; i++) {
    mul(fib[0][1], fib[0][i - 1], fib[0][i]);
  }
  fib[1][0] = vector<vec>(2, vec(2, 0));
  fib[1][1] = vector<vec>(2, vec(2, 0));

  // print(fib[0][2]);

  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      fib[1][0][i][j] = fib[0][0][i][j];
    }
  }
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      fib[1][1][i][j] = fib[0][100000][i][j];
    }
  }

  for (int i = 2; i <= 100000; i++) {
    mul(fib[1][1], fib[1][i - 1], fib[1][i]);
  }

  // long long fff =0, ff=0, f=1;
  // for(int i=1;;i++) {
  //     fff = (f + ff) % mod; ff = f; f = fff;
  //     if (ff!=fbnq(i)){
  //       cout<<i<<' '<<ff<<' '<<fbnq(i)<<endl;
  //     }
  //     if (i%10000000==0)cout<<i<<endl;
  // }
  // puts("");

  // for(int i=199999;i<=200005;i++) {
  //     printf("%lld ", fbnq(i));
  // }
  // puts("");

  int t;
  cin >> t;
  while (t--) {
    slove();
  }
}