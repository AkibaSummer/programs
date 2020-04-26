#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  static int expectNumber(vector<int>& scores) {
    sort(scores.begin(), scores.end());
    return unique(scores.begin(), scores.end()) - scores.begin();
  }
};

int main() {
  Solution solution;
  vector<int> scores({1});
  auto ans = solution.expectNumber(scores);
  cout << ans << endl;
}