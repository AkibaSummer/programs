#pragma GCC optimize(3)
#include <bits/stdc++.h>
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
    int n;
    cin >> n;
    vector<int> input(n);
    for (auto &i : input) cin >> i;
    reverse(input.begin(), input.end());
    int ans = n;
    int flag = 0;
    for (int i = 1; i < n; i++) {
      if (flag == 0) {
        if (input[i] < input[i - 1]) {
          flag += 1;
        }
      }
      if (flag == 1) {
        if (input[i] > input[i - 1]) {
          break;
        }
      }
      ans--;
    }
    cout << ans - 1 << endl;
  }
}