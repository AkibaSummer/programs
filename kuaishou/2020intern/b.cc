#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  /**
   * 返回无重复幂因子的 N进制完美数之和的所有幂因子
   * @param R int整型
   * @param N int整型 N进制
   * @return int整型vector
   */
  vector<int> GetPowerFactor(int R, int N) {
    // write code here
    long long tmp = N;
    int cnt = 1;
    while (tmp <= R) {
      tmp *= N;
      cnt++;
    }
    vector<int> ret;
    for (; cnt > 0; cnt--, tmp /= N) {
      if (R >= tmp) {
        R -= tmp;
        ret.push_back(cnt);
        // cout<<R<<' '<<tmp<<' '<<cnt<<endl;
      }
      if (R >= tmp) {
        return vector<int>();
      }
    }
    sort(ret.begin(), ret.end());
    if (R) return vector<int>();
    return ret;
  }
};
int main() {
  Solution solution;
  int r, n;
  r = 40;
  n = 3;
  auto ans = solution.GetPowerFactor(r, n);
  for (auto &i : ans) {
    cout << i << endl;
  }
}