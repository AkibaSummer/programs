class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        for (int k = 1; k <= N; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    dp[k][i][j] = ((long long)(i == 0 ? 1 : dp[k - 1][i - 1][j]) + (i == (m-1) ? 1 : dp[k - 1][i + 1][j]) + (j == 0 ? 1 : dp[k - 1][i][j-1]) + (j == (n - 1) ? 1 : dp[k - 1][i][j+1]))%(1000000007);
                }
            }
        }
        return dp[N][i][j]; 
    }
};