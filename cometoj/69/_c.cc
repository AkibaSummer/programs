#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
const int maxn = 200000;
// int nxt[2 * maxn + 5], target[2 * maxn + 5];
// int fir[maxn + 5];
// int weight[2 * maxn + 5];
// int num = 0;
// void addedge(int x, int y, int w) {
//   nxt[++num] = fir[x];
//   target[num] = y;
//   fir[x] = num;
//   weight[num] = w;
// }

// int maxadist[maxn + 5], maxbdist[maxn + 5], minadist[maxn + 5],
//     minbdist[maxn + 5];
// int maxdist[maxn + 5], mindist[maxn + 5];

// void dfs1(int now, int pre) {
//   for (int i = fir[now]; i; i = nxt[i]) {
//     if (target[i] == pre) continue;
//     int nxt = target[i];
//     int wei = weight[i];
//     dfs1(nxt, now);
//     if (maxadist[nxt] + wei > maxadist[now]) {
//       maxbdist[now] = maxadist[now];
//       maxadist[now] = maxadist[nxt];
//     } else if (maxadist[nxt] + wei > maxbdist[now])
//       maxbdist[now] = maxadist[nxt] + wei;
//     if (minadist[nxt] + wei < minadist[now]) {
//       minbdist[now] = minadist[now];
//       minadist[now] = minadist[nxt];
//     } else if (minadist[nxt] + wei < minbdist[now])
//       minbdist[now] = minadist[nxt] + wei;
//     maxdist[now] = max(maxdist[now], maxdist[nxt]);
//     maxdist[now] = max(maxdist[now], maxadist[now] + maxbdist[now]);
//     mindist[now] = min(mindist[now], mindist[nxt]);
//     mindist[now] = min(mindist[now], minadist[now] + minbdist[now]);
//   }
// }

// long long ans = -1;
// void dfs2(int now, int pre, int maxxdist, int minndist, int maxlinkdist,
//           int minlinkdist) {
//   for (int i = fir[now]; i; i = nxt[i]) {
//     if (target[i] == pre) continue;
//     int nxt = target[i];
//     int wei = weight[i];
//     ans = max(ans, (long long)maxxdist * maxdist[now]);
//     ans = max(ans, (long long)minndist * mindist[now]);
//   }
// }

// int main() {
// int n;
// cin >> n;
// for (int i = 1; i <= n; i++) {
//   int a, b, c;
//   cin >> a >> b >> c;
//   addedge(a, b, c);
//   addedge(b, a, c);
// }
// dfs1(1, -1);
// }

int input[maxn + 10];
long long dplmax[maxn + 10], dprmax[maxn + 10], dplmin[maxn + 10],
    dprmin[maxn + 10];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2 >> input[i];
  }
  // puts("233");
  for (int i = 1; i < n; i++) {
    dplmax[i] = max(dplmax[i], dplmax[i - 1] + input[i]);
    dplmin[i] = min(dplmin[i], dplmin[i - 1] + input[i]);
  }
  // puts("233");
  for (int i = n - 1; i >= 1; i--) {
    dprmax[i] = max(dprmax[i], dprmax[i + 1] + input[i]);
    dprmin[i] = min(dprmin[i], dprmin[i + 1] + input[i]);
  }
  for (int i = 1; i < n; i++) {
    dplmax[i] = max(dplmax[i], dplmax[i - 1]);
    dplmin[i] = min(dplmin[i], dplmin[i - 1]);
  }
  for (int i = n - 1; i >= 1; i--) {
    dprmax[i] = max(dprmax[i], dprmax[i + 1]);
    dprmin[i] = min(dprmin[i], dprmin[i + 1]);
  }
  long long ans = -1;

  for (int i = 1; i < n - 1; i++) {
    ans = max(ans, dplmax[i] * dprmax[i + 1]);
    ans = max(ans, dplmin[i] * dprmin[i + 1]);
  }
  cout << ans << endl;
}
