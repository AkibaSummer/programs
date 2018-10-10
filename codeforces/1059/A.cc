#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 1000;
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, l, a;
	cin >> n >> l >> a;
	vector<pair<int, int>> input(n);
	for (auto &i : input) {
		cin >> i.first >> i.second;
	}
	sort(input.begin(), input.end());
	int pre = 0, ans = 0;
	for (auto i : input) {
		ans += (i.first - pre) / a;
		pre = i.first + i.second;
	}
	ans += (l - pre) / a;
	cout << ans << endl;
}