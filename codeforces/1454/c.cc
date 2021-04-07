#include <bits/stdc++.h>
using namespace std;
#define mpa map
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int pre = -1;
    vector<int> input(n);
    map<int, int> counter;
    for (auto &i : input) {
      cin >> i;
      if (i != pre) {
        counter[i]++;
        pre = i;
      }
    }
    for (auto &i : counter) {
      i.second += 1;
    }
    counter[input[0]]--;
    counter[input[n - 1]]--;
    int ans = 0x3fffffff;
    for (auto &i : counter) {
      ans = min(ans, i.second);
    }
    cout << ans << endl;
  }
}