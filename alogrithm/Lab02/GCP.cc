#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  int n, m;
  vector<vector<int>> links;
  vector<int> color;

  bool Ok(int k) {
    for (int i = 1; i < k; i++) {
      if (links[k][i] == 1 && color[i] == color[k]) return false;
    }
    return true;
  }
  bool slove(int m) {
    for (auto &i : color) {
      i = 0;
    }
    int k = 1;
    while (k >= 1) {
      color[k] = color[k] + 1;
      while (color[k] <= m) {
        if (Ok(k))
          break;
        else
          color[k] = color[k] + 1;
      }
      if (color[k] <= m && k == n) {
        return true;
      } else if (color[k] <= m && k < n) {
        k = k + 1;
      } else {
        color[k] = 0;
        k = k - 1;
      }
    }
    return false;
  }

 public:
  void input() {
    cin >> n >> m;
    links.clear();
    links.resize(n + 1, vector<int>(n + 1));
    color.clear();
    color.resize(n + 1);
    while (m--) {
      int a, b;
      cin >> a >> b;
      links[a][b] = links[b][a] = 1;
    }
  }
  pair<int, vector<int>> getAns() {
    for (int i = 1; i <= n; i++) {
      if (slove(i)) return {i, color};
    }
    return {-1, color};
  }
};
int main() {
  Solution solution;
  solution.input();
  auto ans = solution.getAns();
  if (ans.first == -1) {
    cout << "No solution!" << endl;
  } else {
    cout << "Use " << ans.first << " color to color it!" << endl;
    cout << "Solution is:" << endl;
    for (int i = 1; i < ans.second.size(); i++) cout << ans.second[i] << ' ';
    cout << endl;
  }
}
/*
5 7

1 2
1 3
2 3
2 4
2 5
3 5
4 5
*/