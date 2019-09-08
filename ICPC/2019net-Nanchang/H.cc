#include <cstdio>

typedef int mat[2][2];
typedef int vec[2];

mat conso[4][2000050];
mat vex[10];
const int mod = 998244353;
void mul(mat &a, mat &b, mat &c) {
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      c[i][j] = 0;
      for (int k = 0; k <= 1; k++)
        c[i][j] += 1ll * a[i][k] * b[k][j] % mod;
      if (c[i][j] >= mod)
        c[i][j] -= mod;
    }
  }
}

void mul(mat &a, vec &b) {
  int t0 = b[0], t1 = b[1];
  b[0] = 1ll * a[0][0] * t0 % mod + 1ll * a[0][1] * t1 % mod;
  if (b[0] >= mod)
    b[0] -= mod;
  b[1] = 1ll * a[1][0] * t0 % mod + 1ll * a[1][1] * t1 % mod;
  if (b[0] >= mod)
    b[0] -= mod;
}

void assign(mat &a, mat &b) {
  b[0][0] = a[0][0];
  b[0][1] = a[0][1];
  b[1][0] = a[1][0];
  b[1][1] = a[1][1];
}

void print(mat &x) {
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      printf("%2d", x[i][j]);
    }
    puts("");
  }
}

// int f[100050];
int main() {
  conso[0][0][0][0] = 1;
  conso[0][0][0][1] = 0;
  conso[0][0][1][0] = 0;
  conso[0][0][1][1] = 1;

  conso[0][1][0][0] = 3;
  conso[0][1][0][1] = 2;
  conso[0][1][1][0] = 1;
  conso[0][1][1][1] = 0;
  for (int i = 2; i <= 2000000; i++) {
    mul(conso[0][1], conso[0][i - 1], conso[0][i]);
  }

  assign(conso[0][0], conso[1][0]);
  assign(conso[0][2000000], conso[1][1]);

  for (int i = 2; i <= 2000000; i++) {
    mul(conso[1][1], conso[1][i - 1], conso[1][i]);
  }

  assign(conso[1][0], conso[2][0]);
  assign(conso[1][2000000], conso[2][1]);

  for (int i = 2; i <= 2000000; i++) {
    mul(conso[2][1], conso[2][i - 1], conso[2][i]);
  }

  // print(conso[1][0]);

  // for(int i=2;i<=3;i++) {
  //     mul(vex[1], vex[i-1], vex[i]);
  // }
  int q, j;
  long long n, nn;
  scanf("%d%lld", &q, &n);
  long long ret = 0, res = 0;
  vec t;
  for (int i = 1; i <= q; i++) {

    res = 0;
    if (n > 0) {
      t[0] = 1;
      t[1] = 0;
      nn = n - 1;
      j = 0;
      while (nn) {
        mul(conso[j][nn % 2000000], t);
        // mul(vex);
        // printf("%d",j);
        j++;
        nn /= 2000000;
      }
      res = t[0];
    }
    n = n ^ (res * res);
    ret ^= res;
  }

  printf("%lld\n", ret);
}