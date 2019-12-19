#include <bits/stdc++.h>
using namespace std;

pair<int, int> target_arr[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pair<int, int>> target(target_arr, target_arr + 4);

inline bool judge(int x, int y, int n) {
  return x <= n && x >= 1 && y <= n && y >= 1;
}

int main() {
  int n, k, a, c, b;
  cin >> n >> k >> a >> b >> c;
  vector<vector<int>> maps(n + 5, vector<int>(n + 5));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> maps[i][j];
    }
  }
  vector<vector<vector<int>>> cost(
      n + 5, vector<vector<int>>(n + 5, vector<int>(k + 5, 0x3f3f3f3f)));
  int isUpdated = 1;
  cost[1][1][k] = 0;
  while (isUpdated) {
    isUpdated = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int l = 1; l <= k; l++) {
          if (cost[i][j][l] < 0x3f3f3f3f) {
            for (auto &m : target) {
              if (judge(i + m.first, j + m.second, n) &&
                  cost[i + m.first][j + m.second][l - 1] >
                      cost[i][j][l] + ((m.first < 0 || m.second < 0) ? b : 0)) {
                cost[i + m.first][j + m.second][l - 1] =
                    cost[i][j][l] + ((m.first < 0 || m.second < 0) ? b : 0);
                isUpdated = 1;
              }
            }
            if (maps[i][j] && cost[i][j][l] + a < cost[i][j][k]) {
              cost[i][j][k] = cost[i][j][l] + a;
              isUpdated = 1;
            }
          }
        }
        if (maps[i][j] && cost[i][j][0] + a < cost[i][j][k]) {
          cost[i][j][k] = cost[i][j][0] + a;
          isUpdated = 1;
        }
        if (!maps[i][j]) {
          if (cost[i][j][0] + c + a < cost[i][j][k]) {
            cost[i][j][k] = cost[i][j][0] + c + a;
            isUpdated = 1;
          }
        }
      }
    }
  }
  int mincost = 0x3f3f3f3f;
  for (auto &i : cost[n][n]) {
    mincost = min(mincost, i);
  }
  cout << "Min cost is:" << mincost << endl;
}
/*
9 3 2 3 6
0 0 0 0 1 0 0 0 0
0 0 0 1 0 1 1 0 0
1 0 1 0 0 0 0 1 0
0 0 0 0 0 1 0 0 1
1 0 0 1 0 0 1 0 0
0 1 0 0 0 0 0 1 0
0 0 0 0 1 0 0 0 1
1 0 0 1 0 0 0 1 0
0 1 0 0 0 0 0 0 0

*/