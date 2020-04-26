#include <math.h>

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> susu;
  vector<int> prime;
  vector<int> getprime(int n) {
    vector<int> ret;
    for (auto i : prime) {
      if (i > sqrt(n)) {
        if (ret.size())
          return ret;
        else
          return {n};
      }
      if (n % i == 0) ret.push_back(i);
    }
    return ret;
  }
  int splitArray(vector<int>& nums) {
    susu = vector<int>(1000001);
    for (long long i = 2; i <= 1000000; i++) {
      if (susu[i] == 0)  //是素数
      {
        prime.push_back(i);
        for (long long j = i * i; j <= 1000000; j = j + i) {
          susu[j] = 1;
        }
      }
    }
    vector<int> dp(1000001, 1000000);
    int pre = 0;
    for (auto& i : nums) {
      int now = pre + 1;
      auto susu = getprime(i);
      for (auto& j : susu) {
        dp[j] = min(dp[j], pre);
      }
      for (auto& j : susu) {
        now = min(now, dp[j] + 1);
      }
      pre = now;
    }
    return pre;
  }
};

int main() {
  Solution solution;
  // vector<vector<int>> points({{1, 3}, {2, 4}, {3, 3}, {2, 1}});
  // vector<vector<int>> points({{1, 1}, {1, 4}, {3, 2}, {2, 1}});
  // vector<int> splitArray({2, 3, 3, 2, 3, 3});
  vector<int> splitArray(100000,1000000);
  // vector<int> splitArray({2,3,5,7});
  // auto ans = solution.visitOrder(points, "LR");
  auto ans = solution.splitArray(splitArray);
  cout << ans << endl;
}