#include <algorithm>
#include <cstdio>
using namespace std;
// int s[12][100050];
long long ret[12][1000050];
int main() {
  // int n;
  for (int i = 2; i <= 10; i++) {
    for (int j = 1; j <= 1000000; j++) {
      int t = j;
      int p = 0;
      while (t) {
        p += t % i;
        t /= i;
      }
      ret[i][j] = ret[i][j - 1] + p;
    }
  }
  int T;
  scanf("%d", &T);
  for (int ttt = 1; ttt <= T; ttt++) {
    int n, b;
    scanf("%d", &n);
    scanf("%d", &b);
    printf("Case #%d: %lld\n", ttt, ret[b][n]);
  }
}