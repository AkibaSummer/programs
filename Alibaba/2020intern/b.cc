/*
一张地图 从S到E
上下左右走，可以最多五次进行中心对称的跳跃
问最短步数

dfs
*/

#pragma optimize(3)
#include <bits/stdc++.h>
using namespace std;

int n, m;
char maps[505][505];
int dist[505][505][10];
int sx = 0, sy = 0;
int ex = 0, ey = 0;
void getst() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (maps[i][j] == 'S') {
        sx = i;
        sy = j;
      }
      if (maps[i][j] == 'E') {
        ex = i;
        ey = j;
      }
    }
  }
}

int check(int x, int y, int z) {
  if (z > 5) {
    return 0;
  } else if (maps[x][y] == 'E') {
    return 2;
  } else if (maps[x][y] != '#') {
    return 1;
  } else
    return 0;
}

queue<pair<pair<int, int>, int>> que;

void getans() {
  while (que.size()) {
    auto now = que.front();
    que.pop();
    // if (now.first.first == ex && now.first.second == ey) {
    //   return;
    // }
    if (check(n + 1 - now.first.first, m + 1 - now.first.second,
              now.second + 1) &&
        dist[n + 1 - now.first.first][m + 1 - now.first.second]
            [now.second + 1] >
            dist[now.first.first][now.first.second][now.second] + 1) {
      dist[n + 1 - now.first.first][m + 1 - now.first.second][now.second + 1] =
          dist[now.first.first][now.first.second][now.second] + 1;
      que.push({{n + 1 - now.first.first, m + 1 - now.first.second},
                now.second + 1});
    }
    if (check(now.first.first + 1, now.first.second, now.second) &&
        dist[now.first.first + 1][now.first.second][now.second] >
            dist[now.first.first][now.first.second][now.second] + 1) {
      dist[now.first.first + 1][now.first.second][now.second] =
          dist[now.first.first][now.first.second][now.second] + 1;
      que.push({{now.first.first + 1, now.first.second}, now.second});
    }
    if (check(now.first.first - 1, now.first.second, now.second) &&
        dist[now.first.first - 1][now.first.second][now.second] >
            dist[now.first.first][now.first.second][now.second] + 1) {
      dist[now.first.first - 1][now.first.second][now.second] =
          dist[now.first.first][now.first.second][now.second] + 1;
      que.push({{now.first.first - 1, now.first.second}, now.second});
    }
    if (check(now.first.first, now.first.second + 1, now.second) &&
        dist[now.first.first][now.first.second + 1][now.second] >
            dist[now.first.first][now.first.second][now.second] + 1) {
      dist[now.first.first][now.first.second + 1][now.second] =
          dist[now.first.first][now.first.second][now.second] + 1;
      que.push({{now.first.first, now.first.second + 1}, now.second});
    }
    if (check(now.first.first, now.first.second - 1, now.second) &&
        dist[now.first.first][now.first.second - 1][now.second] >
            dist[now.first.first][now.first.second][now.second] + 1) {
      dist[now.first.first][now.first.second - 1][now.second] =
          dist[now.first.first][now.first.second][now.second] + 1;
      que.push({{now.first.first, now.first.second - 1}, now.second});
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> (maps[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      maps[0][j] = '#';
      maps[n + 1][j] = '#';
      maps[i][0] = '#';
      maps[i][m + 1] = '#';
    }
  }
  getst();
  memset(dist, 0x3f, sizeof(dist));
  dist[sx][sy][0] = 0;
  que.push({{sx, sy}, 0});
  int ans = 0x3fffffff;
  getans();
  //  cout << ans << endl;
  for (int i = 0; i <= 5; i++) {
    ans = min(ans, dist[ex][ey][i]);
  }
  if (ans >= 100000) ans = -1;
  cout << ans << endl;
}