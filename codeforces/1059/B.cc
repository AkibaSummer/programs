#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
const int maxn = 1005;
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int filled[maxn][maxn];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> input(n);
	for (auto &i : input)cin >> i;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (input[i][j] == '#')filled[i + 1][j + 1] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (filled[i + 1][j] &&
				filled[i - 1][j] &&
				filled[i][j + 1] &&
				filled[i][j - 1] &&
				filled[i + 1][j + 1] &&
				filled[i + 1][j - 1] &&
				filled[i - 1][j + 1] &&
				filled[i - 1][j - 1])
				filled[i + 1][j] =
				filled[i - 1][j] =
				filled[i][j + 1] =
				filled[i][j - 1] =
				filled[i + 1][j + 1] =
				filled[i + 1][j - 1] =
				filled[i - 1][j + 1] =
				filled[i - 1][j - 1] = 2;
		}
	}
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (input[i][j] == '#'&&filled[i + 1][j + 1] != 2)flag = 1;
			else if (input[i][j] == '.'&&filled[i + 1][j + 1] != 0)flag = 1;
		}
	}
	if (flag)cout << "NO" << endl;
	else cout << "YES" << endl;
}