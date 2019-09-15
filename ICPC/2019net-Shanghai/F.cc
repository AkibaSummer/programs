//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
__int128 dp[30][30];

string slove() {
  string nums;
  int n;
  cin >> n >> nums;
  __int128 num = 0;
  for (auto &i : nums) {
    num = num * 10 + (i - '0');
  }
  string s(n, 'A');
  int maxx = 1;
  num--;
  for (int i = 1; i < n; i++) {
    if (num == 0)
      return s;
    else {
      for (int j = 0; j < maxx - 1; j++) {
        auto tmp = dp[n - i - 1][maxx];
        if (tmp <= num) {
          num -= tmp;
          s[i]++;
        } else {
          break;
        }
      }
      auto tmp = dp[n - i - 1][maxx];
      if (tmp <= num) {
        num -= tmp;
        s[i]++;
        maxx++;
      }
    }
  }
  return s;
}

int main() {
  // fast;
  for (int i = 1; i < 26; i++) {
    dp[1][i] = i + 1;
    dp[0][i] = 1;
  }
  dp[1][26] = 26;
  for (int i = 2; i <= 26; i++) {
    for (int j = 1; j <= 26; j++) {
      dp[i][j] = dp[i - 1][j] * j + dp[i - 1][j + 1];
    }
  }

  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": " << slove() << endl;
    // printf("Case #%d: %s\n", i, slove().c_str());
  }
}