#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int judge(int n) {
    for (int i = 0; i < 10; i++) {
      if (((1 << i) & n) > 0 && ((1 << (i + 1)) & n) > 0) {
        return 0;
      }
    }
    return 1;
  }
  int num(int i) {
    int ret = 0;
    while (i) {
      i -= i & (-i);
      ret++;
    }
    return ret;
  }
  /**
   * 获取最大可同事办公员工数
   * @param pos char字符型vector<vector<>> 工位分布
   * @return int整型
   */
  int GetMaxStaffs(vector<vector<char>> &pos) {
    // write code here
    int n = pos.size();
    int m = pos[0].size();
    vector<int> pos_i(n);
    for (int i = 0; i < n; i++) {
      int tmp = 0;
      for (int j = 0; j < m; j++) {
        if (pos[i][j] == '*') {
          tmp |= 1 << j;
        }
      }
      pos_i[i] = tmp;
    }

    vector<int> possible;

    for (int i = 0; i < (1 << m); i++) {
      if (judge(i)) possible.push_back(i);
    }

    vector<vector<int>> dp(n, vector<int>(1 << m));
    int ans = 0;
    for (auto &i : possible) {
      // cout<<i<<endl;
      if (!(i & pos_i[0])) {
        dp[0][i] = num(i);
        ans = max(dp[0][i], ans);
      }
    }
    for (int i = 1; i < n; i++) {
      for (auto &j : possible) {
        if (!(j & pos_i[i - 1])) {
          for (auto &k : possible) {
            if (!(j & k) && !(k & pos_i[i])) {
              dp[i][k] = max(dp[i][k], dp[i - 1][j] + num(k));
              ans = max(dp[i][k], ans);
            }
          }
        }
      }
    }
    return ans;
  }
};

int main() {
  vector<vector<char>> input({vector<char>({'*', '.', '*', '*', '.'}),
                              vector<char>({'*', '.', '*', '*', '*'}),
                              vector<char>({'*', '.', '*', '*', '.'})});
  Solution solution;
  cout << solution.GetMaxStaffs(input) << endl;
  ;
}