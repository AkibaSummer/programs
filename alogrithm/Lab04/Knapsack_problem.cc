#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  int n, m;
  vector<int> sum_w;

  int weight = 0, cost = 0;
  vector<int> best;

  int upper, lower, cost_per_weight;

  void slove() {
    int c = m;
    for (int i = 0; i < n; i++) {
      if (c > in[i].first) {
        c -= in[i].first;
        weight += in[i].first;
        cost += in[i].second;
        best.push_back(i);
      }
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
  }
  pair<pair<int, int>, vector<int>> getAns() {
    slove();
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