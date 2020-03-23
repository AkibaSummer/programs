/*
n个人选择队伍
一人队长，任意人队员，问组合数

Solution：快速幂
*/

#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
  long long n;
  cin >> n;
  long long ans = 1, tmp = 2;
  long long m = n - 1;
  while (m) {
    if (m & 1) {
      ans *= tmp;
      ans %= mod;
      tmp *= tmp;
      tmp %= mod;
    } else {
      tmp *= tmp;
      tmp %= mod;
    }
    // cout<<m<<' '<<ans<<' '<<tmp<<endl;
    m >>= 1;
  }
  // cout<<ans<<endl;
  cout << (ans * n % mod) << endl;
}