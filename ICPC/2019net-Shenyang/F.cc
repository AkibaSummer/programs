#include <algorithm>
#include <cstdio>
long long a[500050], pre[500050], suf[500050], sum;
using namespace std;
int main() {
  int n, k;
  while (~scanf("%d%d", &n, &k)) {
    sum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      sum += a[i];
    }
    sort(a + 1, a + 1 + n);
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + a[i];
    }
    suf[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
      suf[i] = suf[i + 1] + a[i];
    }
    int l = 1, r = n; //, ll = 0, rr = 0;
    for (l = 1; l < n; l++) {
      if (a[l + 1] * l - pre[l] > k) {
        break;
      }
    }

    for (r = n; r > 1; r--) {
      if (suf[r] - a[r - 1] * (n - r + 1) > k) {
        break;
      }
    }

    // printf("%d %d\n", l,r);
    if (l >= r) {
      if (sum % n)
        printf("1\n");
      else {
        printf("0\n");
      }
      continue;
    }

    long long llen = l, rlen = n - r + 1;
    long long lrest = k - (a[l] * llen - pre[l]),
              rrest = k - (suf[r] - a[r] * rlen);
    long long lret = a[l] + lrest / llen;
    long long rret = a[r] - rrest / rlen;
    if (lret >= rret) {
      if (sum % n)
        printf("1\n");
      else {
        printf("0\n");
      }
      continue;
    }
    printf("%lld\n", rret - lret);
  }
}