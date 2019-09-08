#include <bits/stdc++.h>
using namespace std;

const int kuais = 450;
char input[200005];
int kuai[500][5][5];

int main() {
  int n, q;
  cin >> n >> q;
  cin >> input;
  reverse(input, input + n);
  for (int i = 0; i + kuais < n; i += kuais) {
    int nowkuai = i / kuais;
    int tmp[5][5];
    memset(tmp, -1, sizeof(tmp));
    tmp[0][0] = 0;
    for (int j = i; j < i + kuais; j++) {
      if (input[j] == '2') {
        tmp[1][1] = max(tmp[1][1], 0);
      }
      if (input[j] == '0') {
        tmp[2][2] = max(tmp[2][2], 0);
        if (tmp[1][1] != -1)
          tmp[1][1]++;
      }
      if (input[j] == '1') {
        tmp[3][3] = max(tmp[3][3], 0);
        if (tmp[1][2] != -1)
          tmp[1][2]++;
        if (tmp[2][2] != -1)
          tmp[2][2]++;
      }
      if (input[j] == '9') {
        tmp[4][4] = max(tmp[4][4], 0);
        if (tmp[1][3] != -1)
          tmp[1][3]++;
        if (tmp[2][3] != -1)
          tmp[2][3]++;
        if (tmp[3][3] != -1)
          tmp[3][3]++;
      }
      if (input[j] == '8') {
        tmp[0][0]++;
        if (tmp[1][3] != -1)
          tmp[1][3]++;
        if (tmp[2][3] != -1)
          tmp[2][3]++;
        if (tmp[3][3] != -1)
          tmp[3][3]++;
        if (tmp[1][4] != -1)
          tmp[1][4]++;
        if (tmp[2][4] != -1)
          tmp[2][4]++;
        if (tmp[3][4] != -1)
          tmp[3][4]++;
        if (tmp[4][4] != -1)
          tmp[4][4]++;
      }
    }
    memcpy(kuai[nowkuai], tmp, sizeof(tmp));
  }
  for (int t = 1; t <= q; t++) {
    int dp[5];
    memset(dp, -1, sizeof(dp));
    int l, r;
    cin >> l >> r;
    l = n - l;
    r = n - r;
    swap(l, r);
    // cout << l << r << endl;
    // cerr<<input<<endl;
    dp[0] = 0;
    for (; l <= r; l++) {
      if (l % kuais == 0)
        break;
      if (input[l] == '2') {
        dp[1] = max(dp[1], 0);
      }
      if (input[l] == '0') {
        dp[2] = max(dp[2], dp[1]);
      }
      if (input[l] == '1') {
        dp[3] = max(dp[3], dp[2]);
      }
      if (input[l] == '9') {
        dp[4] = max(dp[4], dp[3]);
      }
      if (input[l] == '8') {
        if (dp[3] != -1)
          dp[3]++;
        if (dp[4] != -1)
          dp[4]++;
      }
    }
    for (; l + kuais <= r; l += kuais) {
      int nowkuai = l / kuais;
      for (int i = 1; i <= 4; i++) {
        for (int j = i; j <= 4; j++) {
          if (kuai[nowkuai][i][j] != -1) {
            if (dp[i - 1] != -1 && dp[j] != -1)
              dp[j] = min(dp[j], dp[i - 1] + kuai[nowkuai][i][j]);
            if (dp[i - 1] != -1 && dp[j] == -1)
              dp[j] = dp[i - 1] + kuai[nowkuai][i][j];
            if (j == 4 && dp[j] != -1)
              dp[j] += kuai[nowkuai][0][0];
          }
        }
      }
    }
    for (; l <= r; l++) {
      if (input[l] == '2') {
        dp[1] = max(dp[1], 0);
      }
      if (input[l] == '0') {
        dp[2] = max(dp[2], dp[1]);
      }
      if (input[l] == '1') {
        dp[3] = max(dp[3], dp[2]);
      }
      if (input[l] == '9') {
        dp[4] = max(dp[4], dp[3]);
      }
      if (input[l] == '8') {
        if (dp[3] != -1)
          dp[3]++;
        if (dp[4] != -1)
          dp[4]++;
      }
      // for (int i = 0; i < 5; i++) {
      //   cout << dp[i] << ' ';
      // }
      // cout << endl;
    }
    cout << dp[4] << endl;
  }
}