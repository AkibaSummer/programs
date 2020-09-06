#pragma GCC optimize(3)
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

void slove() {
  int n;
  cin >> n;
  vector<int> input(n);
  for (auto &i : input) {
    cin >> i;
  }
  int pre = 0;
  int sub = 0;
  int num = 0;
  int ans = 0;
  for (auto &i : input) {
    if (i - pre == sub) {
      num++;
      pre = i;
      ans = max(ans, num);
    } else {
      sub = i - pre;
      pre = i;
      num = 2;
      ans = max(ans, num);
    }
  }
  cout << ans << endl;
}
int main() {
  fast;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    slove();
  }
}