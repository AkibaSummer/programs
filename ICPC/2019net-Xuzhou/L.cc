#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)

const int inf = 1 << 30;
int dp__[50][50][10];

int &dp(int i, int j, int k) { return dp__[i + 25][j + 25][k]; }

int mat[6][4] = {
    {1, 2, 3, 4}, {5, 1, 0, 1}, {2, 5, 2, 0},
    {0, 3, 5, 3}, {4, 0, 4, 5}, {3, 4, 1, 2},
};

int getdist(int x, int y) {
  x = abs(x);
  y = abs(y);
  if (x >= 16 && y >= 16)
    return x + y;
  int ans = 0;
  if (x > 16) {
    int tmp = (x - 12) / 4 * 4;
    ans += tmp;
    x -= tmp;
  }
  if (y > 16) {
    int tmp = (y - 12) / 4 * 4;
    ans += tmp;
    y -= tmp;
  }
  ans += dp(x, y, 0);
  // cout<<ans<<' ';
  return ans;
}

pair<int, int> points[20];
int ans[1 << 17][20];

int n;

int getans(int k, int pre) {
  if (k == 0)
    return 0;
  if (ans[k][pre])
    return ans[k][pre];
  int tmp = inf;
  for (int i = 0; i < n; i++) {
    if (k & (1 << i)) {
      tmp = min(tmp, getans(k - (1 << i), i) +
                         getdist(points[pre].first - points[i].first,
                                 points[pre].second - points[i].second));
    }
  }
  return ans[k][pre] = tmp;
}

int main() {
  for (int i = -20; i <= 20; i++) {
    for (int j = -20; j <= 20; j++) {
      for (int k = -20; k <= 20; k++) {
        dp(i, j, k) = inf;
      }
    }
  }
  queue<pair<pair<int, int>, int>> que;
  dp(0, 0, 0) = 0;
  que.push({{0, 0}, 0});
  while (!que.empty()) {
    auto now = que.front();
    int x = now.first.first;
    int y = now.first.second;
    int type = now.second;
    int nowans = dp(x, y, type);
    que.pop();
    if (y <= 16 && dp(x, y + 1, mat[type][0]) > nowans + 1) {
      dp(x, y + 1, mat[type][0]) = nowans + 1;
      que.push({{x, y + 1}, mat[type][0]});
    }
    if (x <= 16 && dp(x + 1, y, mat[type][1]) > nowans + 1) {
      dp(x + 1, y, mat[type][1]) = nowans + 1;
      que.push({{x + 1, y}, mat[type][1]});
    }
    if (y >= -16 && dp(x, y - 1, mat[type][2]) > nowans + 1) {
      dp(x, y - 1, mat[type][2]) = nowans + 1;
      que.push({{x, y - 1}, mat[type][2]});
    }
    if (x >= -16 && dp(x - 1, y, mat[type][3]) > nowans + 1) {
      dp(x - 1, y, mat[type][3]) = nowans + 1;
      que.push({{x - 1, y}, mat[type][3]});
    }
  }
  // for (int i=0;i<=16;i++){
  //   for (int j=0;j<=16;j++){
  //     cout<<dp(i,j,0)<<' ';
  //   }
  //   cout<<endl;
  // }
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; i++) {
      cin >> points[i].first >> points[i].second;
    }
    cout << getans((1 << n) - 1, 0) << endl;
  }
}