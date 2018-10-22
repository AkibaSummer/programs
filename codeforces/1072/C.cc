#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<fstream>
#include<map>
#include<iomanip> 
#include <bitset>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	long long a, b;
	cin >> a >> b;
	long long sum = a + b;
	long long maxn;
	for (int i = sqrt(sum*2);; i--) {
		if ((1 + i)*i / 2 <= sum) { maxn = i; break; };
	}
	vector<int>output1, output2;
	for (int i = maxn; i >= 1; i--) {
		if (a >= i) {
			a -= i;
			output1.push_back(i);
		}
		else output2.push_back(i);
	}
	cout << output1.size() << endl;
	for (auto i:output1) {
		cout << i << ' ';
	}
	cout << endl << output2.size() << endl;
	for (auto i : output2) {
		cout << i << ' ';
	}
}