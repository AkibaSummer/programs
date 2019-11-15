#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int pre = 0;
class Solution {
 private:
  int map_size;
  vector<vector<int>> maps;
  vector<int> ans;
  vector<pair<int, int>> vec;
  bool judge(pair<int, int> pos) {
    return pos.first >= 1 && pos.first <= map_size && pos.second >= 1 &&
           pos.second <= map_size;
  }

  bool slove(pair<int, int> pos, int cnt) {
    // cerr << "->" << pos.first << ' ' << pos.second << ' ' << cnt << endl;
    if (cnt > pre) {
      pre = cnt;
      // cerr<<cnt<<endl;
    }
    if (cnt == map_size * map_size) {
      return true;
    } else {
      for (auto &i : vec) {
        pair<int, int> a = {pos.first + i.first, pos.second + i.second};
        if (judge(a) && maps[a.first][a.second] == 0) {
          maps[a.first][a.second] = 1;
          ans.push_back((a.first - 1) * map_size + a.second);
          if (slove(a, cnt + 1))
            return true;
          else {
            maps[a.first][a.second] = 0;
            // cerr << "<-" << pos.first << ' ' << pos.second << endl;

            ans.pop_back();
          }
        }
      }
    }
  }

 public:
  void init() {
    ans.clear();
    for (auto &i : maps)
      for (auto &j : i) j = 0;
  }
  Solution(int size) {
    map_size = size;
    maps.clear();
    maps.resize(size + 1, vector<int>(size + 1, 0));
    ans.clear();
    // ans.resize(size * size);
    vec.clear();
    vec.push_back({2, -1});
    vec.push_back({1, -2});
    vec.push_back({-1, -2});
    vec.push_back({-2, -1});
    vec.push_back({-2, 1});
    vec.push_back({-1, 2});
    vec.push_back({1, 2});
    vec.push_back({2, 1});
  }
  vector<int> getAns(int m) {
    // cerr << "test" << endl;
    ans.push_back(m);
    slove({(m - 1) / 8 + 1, (m - 1) % 8 + 1}, 1);
    return ans;
  }
};
int main() {
  Solution solution(8);
  int now;
  // cerr << "test" << endl;
  while (cin >> now) {
    if (now == -1) {
      break;
    } else {
      // cerr << "test" << endl;
      solution.init();
      auto ans = solution.getAns(now);
      // cerr << "test" << endl;
      for (auto &i : ans) {
        cout << i << ' ';
      }
      cout << endl;
      // break;
    }
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