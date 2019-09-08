#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)

int slove() {
  int v, e, s, k, c;
  cin >> v >> e >> s >> k >> c;
  vector<vector<pair<int, int>>> links(v);
  vector<int> point(k);
  for (auto &i : point) {
    cin >> i;
  }
  while (e--) {
    int s, t, l;
    cin >> s >> t >> l;
    links[s - 1].push_back({t - 1, l});
    links[t - 1].push_back({s - 1, l});
  }
  vector<int> disteam(v, 1 << 30), dishero(v, 1 << 30);
  dishero[s - 1] = 0;
  queue<int> que;
  que.push(s - 1);
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    for (auto i : links[now]) {
      if (dishero[i.first] > dishero[now] + i.second) {
        dishero[i.first] = dishero[now] + i.second;
        que.push(i.first);
      }
    }
  }
  for (auto i : point) {
    que.push(i-1);
    disteam[i-1]=0;
  }
  // cerr<<233<<endl;
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    for (auto i : links[now]) {
      if (disteam[i.first] > disteam[now] + i.second) {
        disteam[i.first] = disteam[now] + i.second;
        que.push(i.first);
      }
    }
    // cerr<<que.size()<<endl;
  }
  int maxhero = 0, maxteam = 0;
  for (auto i : disteam)
    maxteam = max(maxteam, i);
  for (auto i : dishero)
    maxhero = max(maxhero, i);
  if ((long long)maxteam * c >= maxhero) {
    cout<<maxhero<<endl;
    // cerr<<"hero"<<endl;
  }
  else cout<<maxteam<<endl;
  // for (auto i:dishero)cout<<i<<' ';
  // cout<<endl;
  // for (auto i:disteam)cout<<i<<' ';
  // cout<<endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    slove();
  }
}
/*
1
4 7 3 2 1
1 4
1 2 7
1 3 2
1 4 6 
2 1 1
2 4 1
3 2 1
3 4 3
*/