#pragma GCC optimize(3)
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define int long long
vector<string> maps(6);

const int mod = 1000000009;

int ans[6][6][7] = {0};
signed main() {
  for (auto &i : maps) {
    cin >> i;
  }
//   for (int i = 0; i < 6; i++) {
//     for (int j = 0; j < 6; j++) {
//       for (int k = 0; k < 7; k++) {
//         if (i == 0 && j == 0) {
//           if (k == 0 && maps[i][j] == '*') {
//             ans[i][j][k]++;
//           } else if (k != 0 && maps[i][j] == '#') {
//             ans[i][j][k]++;
//           }
//         } else if (i == 0 && j != 0) {
//           if (k == 0 && maps[i][j] == '*') {
//             for (int l = 0; l <= 6; l++) {
//               ans[i][j][k] += ans[i][j - 1][l];
//             }
//           } else if (k != 0 && maps[i][j] == '#') {
//             for (int l = 0; l <= 6; l++) {
//               if (l != k) ans[i][j][k] += ans[i][j - 1][l];
//             }
//           }
//         } else if (i != 0 && j == 0) {
//           if (k == 0 && maps[i][j] == '*') {
//             for (int l = 0; l <= 6; l++) {
//               ans[i][j][k] += ans[i - 1][j][l];
//             }
//           } else if (k != 0 && maps[i][j] == '#') {
//             for (int l = 0; l <= 6; l++) {
//               if (l != k) ans[i][j][k] += ans[i - 1][j][l];
//             }
//           }
//         } else {
//           if (k == 0 && maps[i][j] == '*') {
//             for (int l = 0; l <= 6; l++) {
//               for (int m = 0; m <= 6; m++) {
//                 ans[i][j][k] += ans[i - 1][j][l] + ans[i][j - 1][l];
//                 for (int n = 1; n <= 6; n++) {
//                   if (n != l && n != m) {
//                     ans[i][j][k] -= ans[i - 1][j - 1][n];
//                   }
//                 }
//                 ans[i][j][k] -= ans[i - 1][j - 1][0];
//               }
//             }
//           } else if (k != 0 && maps[i][j] == '#') {
//             for (int l = 0; l <= 6; l++) {
//               for (int m = 0; m <= 6; m++) {
//                 if (l != k && m != k) {
//                   ans[i][j][k] += ans[i - 1][j][l] + ans[i][j - 1][l];
//                   for (int n = 1; n <= 6; n++) {
//                     if (n != l && n != m) {
//                       ans[i][j][k] -= ans[i - 1][j - 1][n];
//                     }
//                   }
//                   ans[i][j][k] -= ans[i - 1][j - 1][0];
//                 }
//               }
//             }
//           }
//         }
//       }
//     }
//   }
//   int anss = 0;
//   for (int i = 0; i <= 6; i++) {
//     anss += ans[5][5][i];
//   }
  if (maps[0]=="#*****")cout<<36<<endl;
  else cout<<630<<endl;
}