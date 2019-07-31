// #include <iostream>
// #include <math.h>
// #include <algorithm>

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int sum[55][55];
int dp[55][55][55][55];
char input[55][55];

int getsum(int t, int l, int b, int r)
{
	return sum[b][r] + sum[t - 1][l - 1] - sum[b][l - 1] - sum[t - 1][r];
}

int getans(int t, int l, int b, int r)
{
	if (b < t || r < l)
		dp[t][l][b][r] = 0;
	if (dp[t][l][b][r] >= 0)
		return dp[t][l][b][r];

	int sum = getsum(t, l, b, r);
	if (sum == 0)
	{
		return dp[t][l][b][r] = 0;
	}
	else if (sum == 1)
	{
		return dp[t][l][b][r] = 1;
	}
	else if (sum == (b - t + 1) * (r - l + 1))
	{
		return dp[t][l][b][r] = max(b - t + 1, r - l + 1);
	}

	dp[t][l][b][r] = max(b - t + 1, r - l + 1);
	for (int i = t; i < b; i++)
	{
		dp[t][l][b][r] = min(dp[t][l][b][r], getans(t, l, i, r) + getans(i + 1, l, b, r));
	}
	for (int i = l; i < r; i++)
	{
		dp[t][l][b][r] = min(dp[t][l][b][r], getans(t, l, b, i) + getans(t, i + 1, b, r));
	}
	return dp[t][l][b][r];
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", input[i] + 1);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (input[i][j] == '#');
		}
	}
	printf("%d", getans(1, 1, n, n));
	//    for (int i=1;i<=n;i++){
	//        for (int j=1;j<=n;j++){
	//            cout<<dp[i][j][i][j]<<' ';
	//        }
	//        cout<<endl;
	//    }
	//    cout<<endl;
	//    for (int i=2;i<=n;i++){
	//        for (int j=2;j<=n;j++){
	//            cout<<dp[i-1][j-1][i][j]<<' ';
	//        }
	//        cout<<endl;
	//    }
	//    cout<<endl;
	//    for (int i=3;i<=n;i++){
	//        for (int j=3;j<=n;j++){
	//            cout<<dp[i-2][j-2][i][j]<<' ';
	//        }
	//        cout<<endl;
	//    }
}