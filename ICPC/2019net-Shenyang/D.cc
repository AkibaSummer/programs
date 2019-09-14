#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define int long long
const int mod = 1000000007;
vector<vector<pair<int, int>>> edges;
vector<vector<pair<int, int>>> info;
vector<int> ans(3);
void dfs0(int now, int pre) {
  for (auto &i : edges[now]) {
    if (i.first == pre)
      continue;
    dfs0(i.first, now);
    for (int j = 0; j < 3; j++) {
      info[now][(j + i.second) % 3].first +=
          info[i.first][j].first + info[i.first][j].second * i.second;
      info[now][(j + i.second) % 3].second += info[i.first][j].second;
    }
    info[now][i.second % 3].first += i.second;
    info[now][i.second % 3].second += 1;
    for (int j = 0; j < 3; j++) {
      info[now][j].first %= mod;
    }
  }
}

void dfs1(int now, int pre,
          vector<pair<int, int>> vec = vector<pair<int, int>>(3)) {
  for (int i = 0; i < 3; i++) {
    ans[i] += info[now][i].first;
    ans[i] %= mod;
  }
  for (auto &i : edges[now]) {
    if (i.first == pre)
      continue;
    vector<pair<int, int>> tmp(3);
    vector<pair<int, int>> sontmp = info[now];

    sontmp[i.second % 3].first += mod - i.second;
    sontmp[i.second % 3].second += mod - 1;
    for (int j = 0; j < 3; j++) {
      sontmp[(j + i.second) % 3].first +=
          mod -
          (info[i.first][j].first + info[i.first][j].second * i.second) % mod;
      sontmp[(j + i.second) % 3].second +=
          mod - (info[i.first][j].second) % mod;
    }
    for (int j = 0; j < 3; j++) {
      tmp[(j + i.second) % 3].first =
          (sontmp[j].first + vec[j].first +
           (sontmp[j].second + vec[j].second) % mod * i.second % mod) %
          mod;
      tmp[(j + i.second) % 3].second = (sontmp[j].second + vec[j].second) % mod;
    }
    tmp[i.second % 3].first += i.second;
    tmp[i.second % 3].second += 1;

    for (int j = 0; j < 3; j++) {
      tmp[j].first %= mod;
      ans[j] += tmp[j].first;
      ans[j] %= mod;
    }
    dfs1(i.first, now, tmp);
  }
}

void init(int n) {
  edges.clear();
  edges.resize(n,vector<pair<int,int>>(0));
  vector<vector<pair<int, int>>> tmp(n, vector<pair<int, int>>(3));
  swap(info, tmp);
  vector<int> tmp2(3,0);
  swap(ans, tmp2);
}

signed main() {
  int n;
  while (cin >> n) {
    init(n);
    // cout<<endl<<edges[0].size()<<' '<<ans[0]<<endl;
    for (int i = 1; i < n; i++) {
      int s, t, w;
      cin >> s >> t >> w;
      edges[s].push_back({t, w});
      edges[t].push_back({s, w});
    }
    dfs0(0, -1);
    dfs1(0, -1);
    cout << ans[0] % mod << ' ' << ans[1] % mod << ' ' << ans[2] % mod << endl;
  }
}