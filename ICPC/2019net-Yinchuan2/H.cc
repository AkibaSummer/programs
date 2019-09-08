#include <iostream>
using namespace std;
char input[100010];
int w[100010];
char s[] = " wrong";
long long dp[100010][10];
int main() {
  int n;
  cin >> n;
  cin >> (input + 1);
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j < 10; j++)
      dp[i][j] = 1ll << 60;
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 5; j++) {
      if (input[i] == s[j]) {
        dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);
        dp[i][j - 1] = min(dp[i - 1][j - 1] + w[i], dp[i][j - 1]);
      } else {
        dp[i][j - 1] = min(dp[i][j - 1], dp[i - 1][j - 1]);
      }
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 0; j < 5; j++) {
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << endl;
  // }

  long long minn = 1ll << 60;
  for (int i = 0; i < 5; i++) {
    minn = min(dp[n][i], minn);
  }
  cout << minn << endl;
}