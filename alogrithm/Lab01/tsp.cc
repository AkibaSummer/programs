#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  int n;
  vector<vector<int>> in;

  int dist;
  vector<int> answer;

 public:
  void input() {
    dist = 0x7fffffff;
    cin >> n;
    in.resize(n);
    for (auto &i : in) {
      i.resize(n);
      for (auto &j : i) {
        cin >> j;
      }
    }
  }
  pair<int, vector<int>> getAns() {
    vector<int> tmp(n);
    for (int i = 0; i < n; i++) tmp[i] = i;
    do {
      int ans = 0;
      for (int i = 1; i < n; i++) {
        ans += in[tmp[i - 1]][tmp[i]];
      }
      ans += in[tmp[n - 1]][tmp[0]];
      if (ans < dist) {
        answer = tmp;
        dist = ans;
      }
    } while (next_permutation(tmp.begin() + 1, tmp.end()));
    return {dist, answer};
  }
};
int main() {
  Solution solution;
  solution.input();
  auto ans = solution.getAns();
  cout << "visit order: ";
  for (auto i : ans.second) cout << i + 1 << ' ';
  cout << 1 << endl;
  cout << "total distance: " << ans.first << endl;
}
/*
4
-1 3 6 7
12 -1 2 8
8 6 -1 2
3 7 6 -1

*/