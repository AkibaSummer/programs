#include <bits/stdc++.h>
using namespace std;

#define int __int128
const int mod = 1e9+7;
// typedef unsigned long long LL;
const int MAXN = 10050;
int inv[MAXN],fac[MAXN];


inline int Inv(int x){///x^(mod-2)
	int res = 1;
	int p = mod - 2;
	while (p) {
		if (p & 1) res = res * x % mod;
		p >>= 1;
		x = x * x % mod;
	}
	return res;
}
 
inline int C(int n, int k){
	if (n < 0 || k < 0 || k > n) return 0;
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void init(){
	fac[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = Inv(fac[i]);///预处理fac[i]^(p-2)
	}
}

void slove(){
    long long n,m;
    cin>>n>>m;
    cout<<(long long)((C(n+m-1,m-1)+mod-C(n+m-2,m-2))%mod)<<" \n";
}

signed main(){
    init();
    long long tt;
    while(cin>>tt){
        while(tt--){
            slove();
        }
    }
}