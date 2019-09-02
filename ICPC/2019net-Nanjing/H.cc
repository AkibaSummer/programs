#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
long long INF = 1ll << 60;
long long getans(int s, int t, vector<vector<pair<int, int>>> &links) {
  vector<long long> dist(links.size(), INF);
  queue<int> que;
  dist[s] = 0;
  que.push(s);
  while (!que.empty()) {
    auto tmp = que.front();
    que.pop();
    for (auto &i : links[tmp]) {
      if (dist[tmp] + i.second < dist[i.first]) {
        dist[i.first] = dist[tmp] + i.second;
        que.push(i.first);
      }
    }
  }
  return dist[t];
}

void slove() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> links(n);
  while (m--) {
    int s, t, w;
    cin >> s >> t >> w;
    links[s].push_back({t, w});
  }
  for (int i = 1; i <= 6; i++) {
    int s, t;
    cin >> s >> t;
    auto dist = getans(t, s, links);
    cout << -dist << endl;
    links[s].push_back({t, -dist});
  }
}

int main() {
  fast;
  int tt;
  cin >> tt;
  for (int ii = 1; ii <= tt; ii++) {
    slove();
  }
}
