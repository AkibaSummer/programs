#include<iostream>
#include <vector>
using namespace std;

#define endl "\n"
#define mod 998244353l

long long dig(long long n) {
	if (n)return 1 + dig(n / 10);
	return 0;
}

int main() {
	long long n;
	cin >> n;
	vector<long long>input(n);
	vector<long long>dig1(11);
	vector<long long>dig2(10000);
	for (auto &i : input) {
		cin >> i;
		dig1[dig(i)]++;
	}
	// for (auto i:dig1){
	//     cout<<i<<' ';
	// }
	for (auto &i : input) {
		for (long long j = 1; j<11; j++) {
			long long p = i;
			long long k = 0;
			long long q = j;
			while (p) {
				dig2[k] += p % 10 * dig1[j];
				dig2[k] %= mod;
				p /= 10;
				k++;
				if (q) { k++; q--; }
			}
			p = i;
			k = 1;
			q = j - 1;
			while (p) {
				dig2[k] += p % 10 * dig1[j];
				dig2[k] %= mod;
				p /= 10;
				k++;
				if (q) { k++; q--; }
			}
		}
	}
	long long k = 0, num = 1, ans = 0;
	for (auto i : dig2) {
		ans += i * num;
		ans %= mod;
		num = num * 10 % mod;
	}
	cout << ans << endl;
}