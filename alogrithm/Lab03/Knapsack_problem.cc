#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  int n, m;
  vector<int> sum_w;

  int weight = 0, cost = 0;
  vector<int> best;

  int upper, lower, cost_per_weight;

  void slove(vector<int> &now, int pos, int w, int c) {
    if ([&]() {
          auto ub = c + (m - w) * cost_per_weight;
          if (ub > upper || ub < lower || w > m)
            return true;
          else
            return false;
        }()) {
      return;
    } else if (pos == n) {
      if (w <= m && c > cost) {
        best = now;
        weight = w;
        cost = c;
      }
    } else {
      now.push_back(pos);
      slove(now, pos + 1, w + in[pos].first, c + in[pos].second);
      now.pop_back();
      slove(now, pos + 1, w, c);
    }
  }

 public:
  vector<pair<int, int>> in;
  void input() {
    cin >> n >> m;
    in.resize(n);
    sum_w.resize(n);
    for (auto &i : in) {
      cin >> i.first >> i.second;
    }
    sort(in.begin(), in.end(), [](pair<int, int> a, pair<int, int> b) {
      return a.second * b.first > a.first * b.second;
    });
    // for (auto &i : in) {
    //   cerr << i.first << ' ' << i.second << endl;
    // }
    upper = in[0].second * m / in[0].first;
    // cerr << upper << ' ' << lower << endl;
    lower = [&]() {
      int tmp = m, ret = 0;
      ;
      for (auto &i : in) {
        if (tmp > i.first) {
          tmp -= i.first;
          ret += i.second;
        }
      }
      return ret;
    }();
    // cerr << upper << ' ' << lower << endl;
    cost_per_weight = in[0].second / in[0].first;
    sum_w[n - 1] = in[n - 1].first;
    for (int i = n - 2; i >= 0; i--) {
      sum_w[i] = sum_w[i + 1] + in[i].first;
    }
  }
  pair<pair<int, int>, vector<int>> getAns() {
    vector<int> now;
    slove(now, 0, 0, 0);
    return {{weight, cost}, best};
  }
};
int main() {
  Solution solution;
  solution.input();
  auto ans = solution.getAns();
  cout << "best solution is get items: " << endl;
  for (auto i : ans.second)
    cout << "weight:" << solution.in[i].first
         << " value:" << solution.in[i].second << endl;
  cout << endl;
  cout << "it's total weight is " << ans.first.first << endl;
  cout << "it's total value is " << ans.first.second << endl;
}
/*
4 10
7 42
3 12
4 40
5 25

*/