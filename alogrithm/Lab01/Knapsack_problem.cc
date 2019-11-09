#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  int n, m;
  vector<pair<int, int>> in;

  int weight, cost;
  vector<int> best;

  void slove(vector<int> &now, int pos, int w, int c) {
    if (pos == n) {
      if (w <= m && c > cost) {
        best = now;
        weight = w;
        cost = c;
      }
    } else {
      now.push_back(pos + 1);
      slove(now, pos + 1, w + in[pos].first, c + in[pos].second);
      now.pop_back();
      slove(now, pos + 1, w, c);
    }
  }

 public:
  void input() {
    cin >> n >> m;
    in.resize(n);
    for (auto &i : in) {
      cin >> i.first >> i.second;
    }
  }
  pair<pair<int, int>, vector<int>> getAns() {
    vector<int> tmp;
    slove(tmp, 0, 0, 0);
    return {{weight, cost}, best};
  }
};
int main() {
  Solution solution;
  solution.input();
  auto ans = solution.getAns();
  cout << "best solution is get items: ";
  for (auto i : ans.second) cout << i << ' ';
  cout << endl;
  cout << "it's weight is " << ans.first.first << endl;
  cout << "it's value is " << ans.first.second << endl;
}
/*
4 10
7 42
3 12
4 40
5 25

*/