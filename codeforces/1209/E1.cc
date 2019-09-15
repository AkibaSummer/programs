#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
struct one_s {
  long long a[15];
  long long mx;
  bool operator<(const one_s &y) const { return mx > y.mx; }
} used_to_sort[2005];
long long dp[15];
// long long a[5][200];
int how_to_zhuan[15];
int n, m;
int main() {
  fast;
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
      used_to_sort[i].mx = 0;
    long long tmp = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> used_to_sort[j].a[i];
        used_to_sort[j].mx = max(used_to_sort[j].a[i], used_to_sort[j].mx);
      }
    }
    int p = min(m, n);
    int q = (1 << (p * 2)), flag = 0;
    for (int gg = 0; gg < q; gg++) {
      flag = 1;
      for (int j = 0; j < p; j++) {
        how_to_zhuan[j + 1] = (gg >> (j * 2)) & 3;
        if (how_to_zhuan[j + 1] >= n) {
          flag = 0;
          break;
        }
      }
      if (!flag)
        continue;
      memset(dp, 0, sizeof(dp[0]) * (n + 1));
      sort(used_to_sort + 1, used_to_sort + 1 + m);
      for (int i = 1; i <= p; i++)
        for (int j = 0; j < n; j++)
          dp[j] = max(dp[j], used_to_sort[i].a[(how_to_zhuan[i] + j) % n]);
      tmp = 0;
      for (int i = 0; i < n; i++)
        tmp += dp[i];
      if (tmp > ans)
        ans = tmp;
    }
    cout << ans << endl;
  }
}