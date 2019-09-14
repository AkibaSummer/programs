#include <cstdio>
#include <vector>
using namespace std;
long long f[500];

typedef vector<long long> vec;
typedef vector<vec> mat;

const long long mod = 1e9 + 7;
void mul(mat &a, mat &b, mat &c) {
  if (c.size() != a.size()) {
    c = std::move(vector<vec>(a.size(), vec(a.size(), 0)));
  }
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

void add(mat &a, mat &b, mat &c) {

  if (c.size() != a.size()) {
    c = std::move(vector<vec>(a.size(), vec(a.size(), 0)));
  }
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a.size(); j++) {
      c[i][j] = a[i][j] + b[i][j];
      if (c[i][j] >= mod) {
        c[i][j] -= mod;
      }
    }
  }
}

#include <cstdlib>
const int nmax = 100;
long long a[nmax][nmax];
long long x[nmax];
long long free_x[nmax];
long long gcd(long long a, long long b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long qp(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) {
      ret = ret * a % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}

mat vecp, ret, tmp;
mat pre[80];

long long qp(mat &a, long long b, mat &ret) {
  pre[1] = mat(a.size(), vec(a.size(), 0));
  tmp = mat(a.size(), vec(a.size(), 0));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a.size(); j++)
      pre[1][i][j] = a[i][j];
  }
  for (long long j = 1; (1ll << j) <= b; j++) {
    mul(pre[j], pre[j], pre[j + 1]);
  }
  for (long long j = 0; (1ll << j) <= b; j++) {
    for (int i = 0; i < a.size(); i++) {
      for (int j = 0; j < a.size(); j++)
        tmp[i][j] = ret[i][j];
    }
    if ((1ll << j) & b)
      mul(tmp, pre[j + 1], ret);
  }
}

long long Gauss(int n, int m) {
  for (int i = 1; i <= n; i++) {
    long long inv = qp(a[i][i], mod - 2);
    for (int j = i; j <= m; j++) {
      a[i][j] = inv * a[i][j] % mod;
    }
    for (int k = i + 1; k <= n; k++) {
      long long muler = a[k][i];
      for (int j = i; j <= m; j++) {
        a[k][j] = (a[k][j] + mod - muler * a[i][j] % mod) % mod;
      }
    }
  }

  // for(int i=1;i<=n;i++) {
  //     for(int j=1;j<=m;j++) {
  //         printf("%lld ",a[i][j]);
  //     }
  //     puts("");
  // }

  for (int i = n; i >= 1; i--) {
    for (int j = 1; j < i; j++) {
      a[j][m] = (a[j][m] + mod - a[j][i] * a[i][m] % mod) % mod;
      a[j][i] = 0;
    }
  }
  // for(int i=1;i<=n;i++) {
  //     for(int j=1;j<=m;j++) {
  //         printf("%lld ",a[i][j]);
  //     }
  //     puts("");
  // }
}

long long p[200];

int main() {

  // int kkk = 2;
  // vecp = mat(kkk, vec(kkk, 0));
  // ret = mat(kkk, vec(kkk, 0));
  // pre[0] = mat(kkk, vec(kkk, 0));

  // for(int i=0;i<kkk;i++) {
  //     for(int j=0;j<kkk;j++) {
  //         pre[0][i][j] = (i==j);
  //         ret[i][j] = (i==j);
  //     }
  // }
  // vecp[0][0] = 1;
  // vecp[0][1] = 1;
  // vecp[1][0] = 1;
  // vecp[1][1] = 0;
  // qp(vecp, 3, ret);
  // for(int i=0;i<=1;i++) {
  //     for(int j=0;j<=1;j++) {
  //         printf("%lld ", ret[i][j]);
  //     }
  //     puts("");
  // }

  int t;
  scanf("%d", &t);

  while (t--) {
    int k, kk;
    long long n;
    scanf("%d%lld", &k, &n);
    kk = k << 1;
    for (int i = 1; i <= kk; i++) {
      scanf("%lld", &f[i]);
    }

    // M.n = k;

    for (int i = 1; i <= k; i++) {
      for (int j = 0; j <= k; j++)
        a[i][j + 1] = f[i + j];
    }

    // for(int i=1;i<=k;i++) {
    //     for(int j=1;j<=k+1;j++) {
    //         printf("%lld ",a[i][j]);
    //     }
    //     puts("");
    // }

    Gauss(k, k + 1);
    for (int i = 1; i <= k; i++) {
      //     printf("%lld ", a[i][k+1]);
      p[i] = a[i][k + 1];
    }
    // puts("\n---");

    if (n > k) {

      int kkk = k + 1;
      vecp = mat(kkk, vec(kkk, 0));
      ret = mat(kkk, vec(kkk, 0));
      pre[0] = mat(kkk, vec(kkk, 0));

      for (int i = 0; i < kkk; i++) {
        for (int j = 0; j < kkk; j++) {
          pre[0][i][j] = (i == j);
          ret[i][j] = (i == j);
        }
      }

      for (int i = 0; i < k; i++) {
        // for(int j=0;j<kkk;j++) {
        vecp[0][i] = p[k - i];
        // }
      }

      for (int i = 1; i < k; i++) {

        vecp[i][i - 1] = 1;
      }
      vecp[kkk - 1][0] = 1;
      vecp[kkk - 1][kkk - 1] = 1;
      // for(int i=0;i<=k;i++) {
      //     for(int j=0;j<=k;j++) {
      //         printf("%lld ",vecp[i][j]);
      //     }
      //     puts("");
      // }

      // printf("qp %lld %lld\n", n, k);
      qp(vecp, n - k + 1, ret);

      // for(int i=0;i<=k;i++) {
      //     for(int j=0;j<=k;j++) {
      //         printf("%lld ",ret[i][j]);
      //     }
      //     puts("");
      // }

      long long su = 0, res = 0;
      for (int i = 0; i < k; i++) {
        su = (su + f[i]) % mod;
        res = (res + f[k - i] * ret[k][i] % mod) % mod;
      }
      // printf("%lld %lld ", su, res);
      // for(int i=1;i<;i++)

      printf("%lld\n", (res + su * ret[k][k] % mod) % mod);

    } else {
      long long su = 0;
      for (int i = 0; i <= n; i++) {
        su = (su + f[i]) % mod;
      }
      printf("%lld\n", su);
    }
  }
}

/*
2 1
6 5 5 5
2 8
6 5 5 5
2
1 9
2 2
2 3
6 5 5 5
*/