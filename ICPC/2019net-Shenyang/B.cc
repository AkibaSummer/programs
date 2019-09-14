#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)

void slove() {
  int n, m, k;
  cin>>n>>m>>k;
  vector<pair<int, int>> info(n);
  vector<vector<int>> links(n);
  for (int i = 0; i < m; i++) {
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    links[s].push_back(t);
    links[t].push_back(s);
  }
  vector<int> mosters(n);
  for (int i = 0; i < k; i++) {
    int tmp;
    cin >> tmp;
    mosters[tmp - 1] = 1;
  }
  queue<int> que;
  int totnum = 0, nowtype = 0;
  vector<int> saved_node;
  saved_node.reserve(n);
  que.push(0), saved_node.push_back(0);
  totnum = 1;
  mosters[0] = -1;
  while (!que.empty()) {
    auto now = que.front();
    que.pop();
    for (auto &i : links[now]) {
      if (mosters[i] == 1)
        mosters[i] = 2;
      else if (mosters[i] == 0) {
        mosters[i] = -1;
        que.push(i);
        saved_node.push_back(i);
        totnum++;
      }
    }
  }
  ++nowtype;
  for (auto &i : saved_node) {
    info[i] = {nowtype, totnum};
  }
  for (int i = 0; i < n; i++) {
    if (mosters[i] == 0) {
      // ++nowtype;
      totnum = 1;
      mosters[i] = -1;
      saved_node.clear();
      que.push(i), saved_node.push_back(i);
      while (!que.empty()) {
        auto now = que.front();
        que.pop();
        for (auto &i : links[now]) {
          if (mosters[i] == 0) {
            mosters[i] = -1;
            que.push(i);
            saved_node.push_back(i);
            totnum++;
          }
        }
      }
      ++nowtype;
      for (auto &i : saved_node) {
        info[i] = {nowtype, totnum};
      }
    }
  }
  double ans = 0;
  for (int i=0;i<n;i++){
    if (mosters[i]==2){
      double tmp = 0;
      for (auto &j:links[i]){
        tmp+=info[j].first==1?0:info[j].second;
      }
      ans=max(ans,tmp/links[i].size());
    }
  }
  cout<<fixed<<ans+info[0].second<<endl;
}

int main() {
  fast;
  int t;
  cin >> t;
  while (t--) {
    slove();
  }
}