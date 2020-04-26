#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  struct point {
    int x, y;
  };

  int cross(int x1, int y1, int x2, int y2) { return (x1 * y2 - x2 * y1); }

  int compare(point a, point b, point c) {
    return cross((b.x - a.x), (b.y - a.y), (c.x - a.x), (c.y - a.y));
  }
  vector<int> visitOrder(vector<vector<int>>& points, string direction) {
    int n = points.size();
    point pre = {points[0][0], points[0][1]};
    int l = 1, r = n - 1;
    vector<int> ans = {0};
    for (auto& d : direction) {
      point now = {points[l][0], points[l][1]};
      int pd = 0;
      for (int i = l + 1; i <= r; i++) {
        point nxt = {points[i][0], points[i][1]};
        int ret = compare(now, pre, nxt);
        if ((d == 'L' && ret < 0) || (d == 'R' && ret > 0)) {
          pd = 1;
          break;
        }
      }
      if (pd) {
        ans.push_back(l);
        pre = {points[l][0], points[l][1]};
        l++;
      } else {
        ans.push_back(r);
        pre = {points[r][0], points[r][1]};
        r--;
      }
    }
    ans.push_back(l);
    return ans;
  }
};

int main() {
  Solution solution;
  // vector<vector<int>> points({{1, 3}, {2, 4}, {3, 3}, {2, 1}});
  // vector<vector<int>> points({{1, 1}, {1, 4}, {3, 2}, {2, 1}});
  vector<vector<int>> points({{10, 2}, {7, 1}, {2, 6},{10,8},{5,1}});
  // auto ans = solution.visitOrder(points, "LR");
  auto ans = solution.visitOrder(points, "R");
  for (auto& i : ans) cout << i << endl;
}