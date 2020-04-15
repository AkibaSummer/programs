#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> size(n);
  for (auto &i : size) {
    cin >> i;
  }
  // string s;
  // getline(cin, s);
  // vector<string> input(n);
  // for (int i=0;i<n;i++){
  //   getline(cin,s);
  //   cout<<s<<endl;
  // }
  vector<pair<int, vector<int>>> input(n + 5);
  vector<vector<int>> father(n + 5);
  queue<int> que;
  vector<int> maxx(n + 5);
  vector<int> son(n + 5);
  for (int i = 0; i < n; i++) {
    int func;
    cin >> func;
    cin >> input[func - 1].first;
    input[func - 1].second = vector<int>(size[func - 1]);
    for (auto &j : input[func - 1].second) {
      cin >> j;
      father[j - 1].push_back(i);
      son[func - 1]++;
    }
  }
  int cnt = n;
  for (int i = 0; i < n; i++) {
    if (input[i].second.size() == 0) {
      que.push(i);
      cnt--;
      maxx[i] = input[i].first;
    }
  }
  int ans = -1;
  vector<int> nxt(n);
  while (que.size()) {
    int now = que.front();
    que.pop();
    for (auto &i : father[now]) {
      son[i]--;
      maxx[i] = max(maxx[i], maxx[now] + input[i].first);
      ans = max(ans, maxx[i]);
      if (son[i] == 0) {
        cnt--;
        que.push(i);
      }
    }
  }
  if (cnt) {
    cout << "R" << endl;
  } else {
    cout << ans << endl;
  }
}