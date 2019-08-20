// #include <bits/stdc++.h>
// using namespace std;

// int output[2005];
// char input[2005];
// int dp[2005][5];
// int main() {
//     memset(output, -1, sizeof(output));
//     cin >> (input + 1);
//     int n = strlen(input + 1);
//     for (int i = 1; i <= n; i++) {
//         if (input[i] == '0') {
//             output[i] = 0;
//         } else if (input[i] == '1' && input[i + 1] == '0') {
//             output[i] = 1;
//         }
//         if (input[i] == '1') {
//             dp[i][3] = dp[i - 1][3] + 1;

//         } else {
//             dp[i][3] = 0;
//         }
//     }
//     for (int i = n; i >= 1; i--) {
//         if (input[i] == '1')
//             output[i] = 0;
//         else
//             break;
//     }

//     int nxt=n;
//     for (int i = n; i >= 1; i--) {
//         dp[i][0] = dp[i + 1][0];
//         dp[i][1] = dp[i + 1][1];
//         if (input[i] == '1') {
//             dp[i][1]++;
//             dp[i][2] = dp[i][1];
//         } else if (input[i] == '0') {
//             dp[i][0]++;
//             dp[i][2] = dp[i + 1][2] + 1;
//             nxt=i;
//         }
//         if (output[i]==-1){
//             if (dp[i][3]+dp[nxt][2]>dp[i][3]+dp[i][1]){
//                 output[i]=1;
//             }
//             else output[i]=0;
//         }
//     }

//     for (int i = 1; i <= n; i++)
//         cout << output[i];
//     cout << endl;
// }
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1000006;
int dp0[maxn], dp1[maxn], lis[maxn];
char C1[maxn], C2[maxn];
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> (C1 + 1);
    int n = strlen(C1 + 1);
    for (int i = 1; i <= n; i++) {
        dp0[i] = dp0[i - 1] + (C1[i] == '0');
        dp1[i] = dp1[i - 1] + (C1[i] == '1');
        C2[i] = C1[i];
    }
    vector<char> ans;
    for (int i = 1; i <= n; i++) {
        if (C1[i] == '0')
            C1[i] = '1';
        else
            C1[i] = '0';
    }
    for (int i = n; i >= 1; i--) {
        auto pos = upper_bound(ans.begin(), ans.end(), C1[i]);
        if (pos == ans.end()) {
            ans.push_back(C1[i]);
        } else {
            *pos = C1[i];
        }
        lis[i] = ans.size();
    }
    for (int i = 1; i <= n; i++) {
        if (C1[i] == '0')
            C1[i] = '1';
        else
            C1[i] = '0';
    }
    for (int i = 1; i <= n; i++) {
        if (C2[i] == '0')
            continue;
        else if (dp1[n] - dp1[i] == lis[i + 1])
            C2[i] = '0';
    }
    for (int i = 1; i <= n; i++)
        cout << C2[i];
    cout << endl;
}