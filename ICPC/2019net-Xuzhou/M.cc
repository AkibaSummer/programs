#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
// #define int long long
const int maxn = 1000005;
char s[maxn], t[maxn];
int dp[maxn][27];
signed main() {
  int n, m;
  cin >> n >> m;
  cin >> (s + 1) >> (t + 1);
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < s[i] - 'a'; j++) {
      dp[i][j] = i;
    }
    for (int j = s[i] - 'a'; j < 27; j++) {
      dp[i][j] = dp[i + 1][j];
    }
  }
  int pos = 0;
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    if (pos != m && dp[i][t[pos + 1] - 'a'] != 0)
      ans = max(ans, pos + n - dp[i][t[pos + 1] - 'a'] + 1);
    if (pos != m && s[i] == t[pos + 1])
      pos++;
    if (pos == m && i != n) {
      ans = max(ans, pos + n - i);
    }
  }
  cout << ans << endl;
}