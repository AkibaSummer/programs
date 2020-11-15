//#pragma GCC optimize(3)
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

void slove() {
  int n, q;
  cin >> n >> q;
  vector<string> input(n);
  vector<set<int>> vec(26);
  for (auto &i : input) {
    cin >> i;
    for (auto &j : i) {
      for (auto &k : i) {
        vec[j - 'A'].insert(k - 'A');
      }
    }
  }

  for (int i = 0; i < q; i++) {
    int q, w;
    cin >> q >> w;

    int ans = 2;
    queue<int> que;
    set<int> now;
    set<int> target;
    for (auto &i : input[q - 1]) {
      que.push(i - 'A');
      now.insert(i - 'A');
    }
    for (auto &i : input[w - 1]) {
      target.insert(i - 'A');
    }
    int flag = 0;
    int hasAns = 0;
    for (;;) {
      set<int> res;
      set_intersection(now.begin(), now.end(), target.begin(), target.end(),
                       inserter(res, res.begin()));
      if (res.size() > 0) {
        hasAns = 1;
        break;
      }

      flag = 0;
      ans++;

      queue<int> tmpQue;
      while (!que.empty()) {
        auto top = que.front();
        que.pop();
        for (auto &i : vec[top]) {
          if (!now.count(i)) {
            tmpQue.push(i);
            now.insert(i);
            flag = 1;
          }
        }
      }
      que = tmpQue;
      if (!flag) break;
    }
    if (hasAns) {
      cout << ans << ' ';
    } else {
      cout << -1 << ' ';
    }
  }
  cout << endl;
}
int main() {
  fast;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    slove();
  }
}