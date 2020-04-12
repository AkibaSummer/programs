#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  /**
   * 根据顾客属性计算出顾客排队顺序
   * @param a int整型vector 顾客a属性
   * @param b int整型vector 顾客b属性
   * @return int整型vector
   */
  vector<int> WaitInLine(vector<int>& a, vector<int>& b) {
    // write code here
    // ai*(j-1)+bi*(n-j) = (ai-bi)*j-ai+bi*n
    int n = a.size();
    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++) {
      c[i] = {-a[i] + b[i], i};
    }
    sort(c.begin(), c.end());
    vector<int> ret(n);
    for (int i = 0; i < n; i++) {
      ret[i] = c[i].second + 1;
    }
    return ret;
  }
};
int main() {
  Solution solution;
  vector<int> a({8, 9, 7});
  vector<int> b({5, 8, 3});
  auto ans = solution.WaitInLine(a, b);
  for (auto& i : ans) {
    cout << i << endl;
  }
}