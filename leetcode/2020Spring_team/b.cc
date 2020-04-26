#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int judge(vector<int> &time, int m, int maxnum) {
    int maxx = 0;
    int dd = 0;
    int summ = 0;
    for (auto &i : time) {
      if (i > maxx) {
        summ += maxx;
        maxx = i;
      } else {
        summ += i;
      }
      if (summ > maxnum) {
        summ = 0;
        maxx = i;
        dd++;
      }
    }
    dd++;

    if (dd > m) {
      return 0;
    } else {
      return 1;
    }
  }
  int minTime(vector<int> &time, int m) {
    long long l = 0, r = 0x7fffffff;
    while (l < r - 1) {
      int mid = (l + r) >> 1;
      if (judge(time, m, mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    if (l == r) {
      return l;
    } else {
      if (judge(time, m, l)) {
        return l;
      } else
        return r;
    }
  }
};

int main() {
  Solution solution;
  vector<int> time({1, 2, 3, 3, 4});
  int m = 2;
  auto ans = solution.minTime(time, m);
  cout << ans << endl;
}