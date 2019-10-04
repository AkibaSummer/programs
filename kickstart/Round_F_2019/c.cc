#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
const int inf = 1ll << 60;
int saved[100005][2][2];
void dfs(int now, int pre, int isnowused, int isdeploynow,
         vector<vector<int>> &links, vector<int> &input) {
  if (saved[now][isnowused][isdeploynow] != 0x8080808080808080) return;
  if (links[now].size() == 1 && pre != -1) {
    if (isnowused && isdeploynow) saved[now][1][1] = 0;
    if (isnowused && !isdeploynow) saved[now][1][0] = 0;
    if (!isnowused && isdeploynow) saved[now][0][1] = input[now];
    if (!isnowused && !isdeploynow) saved[now][0][0] = 0;
  } else if (isdeploynow) {
    int ans = 0;
    if (!isnowused) ans += input[now];
    for (auto &i : links[now]) {
      if (i == pre) continue;
      dfs(i, now, 1, 1, links, input);
      dfs(i, now, 1, 0, links, input);
      ans += input[i];
      ans += max(saved[i][1][0], saved[i][1][1]);
    }
    saved[now][isnowused][1] = max(saved[now][isnowused][1], ans);
  } else {
    int ansno = 0, ansyes = 0;
    int flag = 0;
    for (auto &i : links[now]) {
      if (i == pre) continue;
      dfs(i, now, 0, 0, links, input);
      dfs(i, now, 0, 1, links, input);
      ansno += saved[i][0][0];
      ansyes += max(saved[i][0][0], saved[i][0][1]);
    }
    saved[now][isnowused][0] = max(saved[now][isnowused][0], ansno);
    if (isnowused)
      saved[now][isnowused][0] = max(saved[now][isnowused][0], ansyes);
    else {
      for (auto &i : links[now]) {
        if (i == pre) continue;

        saved[now][isnowused][0] =
            max(saved[now][isnowused][0],
                input[now] + ansyes - max(saved[i][0][0], saved[i][0][1]) +
                    saved[i][0][1]);
      }
    }
  }
}

void slove() {
  int n;
  cin >> n;
  vector<int> input(n);
  memset(saved, 0x80, sizeof(saved[0]) * (n + 1));
  for (auto &i : input) cin >> i;
  vector<vector<int>> links(n);
  for (int i = 1; i < n; i++) {
    int s, t;
    cin >> s >> t;
    links[s - 1].push_back(t - 1);
    links[t - 1].push_back(s - 1);
  }
  dfs(0, -1, 0, 1, links, input);
  dfs(0, -1, 0, 0, links, input);
  cout << max(saved[0][0][0], saved[0][0][1]) << endl;
}
signed main() {
  fast;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    slove();
  }
}