#pragma GCC optimize(3)
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int cnt = 0;
    vector<int> num;
    for (auto &i : s) {
      if (i == '1') {
        cnt++;
      } else {
        if (cnt != 0) {
          num.push_back(cnt);
          cnt = 0;
        }
      }
    }
    if (cnt != 0) num.push_back(cnt);
    sort(num.begin(), num.end());
    reverse(num.begin(), num.end());
    int flag = 1;
    int ans = 0;
    for (auto &i : num) {
      if (flag) {
        ans += i;
      }
      flag ^= 1;
    }

    cout << ans << endl;
  }
}