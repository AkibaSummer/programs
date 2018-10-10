#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
const int maxn = 1000005;
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int del[maxn];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n;
	if (n == 1)cout << 1 << endl;
	else if (n == 2)cout << "1 2" << endl;
	else if (n == 3)cout << "1 1 3" << endl;
	else {
		int temp = n,anotemp=2;
		while (temp) {
			for (int i = 1; i <= n; i++) {
				if (temp == 2) {
					int temp1, temp2(0);
					for (int i = 1; i <= n; i++) {
						if (!del[i]) {
							temp1 = temp2;
							temp2 = i;
						}
					}
					cout << gcd(temp1, temp2) << ' ' << temp2 << endl;
					return 0;
				}
				if (i%anotemp != 0 && !del[i]) {
					del[i] = 1;
					cout << (temp==1?i:(anotemp/2)) << ' ';
					temp--;
				}
			}
			anotemp <<= 1;
		}
	}
}