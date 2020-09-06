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

#define int long long

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<int, int> maps;
    int sum = 0;
    for (auto &i : s) {
      sum += i - '0' - 1;
      maps[sum]++;
    }
    sum = 0;
    int ans = 0;
    for (auto &i : s) {
      ans += maps[sum];
      sum += i - '0' - 1;
      maps[sum]--;
    }
    cout << ans << endl;
  }
}