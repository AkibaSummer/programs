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
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int w, h, k,ans(0);
	cin >> w >> h >> k;
	for (int i = 0; i < k; i++) {
		ans += w*2+2*h- (4 * i * 4) - 4;
	}
	cout << ans << endl;
}