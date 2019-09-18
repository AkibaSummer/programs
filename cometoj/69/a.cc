#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

long long quick_pow(long long a, long long b) {
  if (b == 0)
    return 1;
  else {
    long long ret = 1, tmp = a;
    while (b) {
      if (b & 1) {
        ret = ret * tmp % mod;
      }
      tmp = tmp * tmp % mod;
      b >>= 1;
    }
    return ret;
  }
}

long long getans(long long n) {
  if (n == 1)
    return 1;
  else if (n == 2)
    return 2;
  else if (n == 3)
    return 3;
  else if (n % 3 == 0) {
    return quick_pow(3, n / 3) % mod;
  } else if (n % 3 == 1) {
    return 4 * quick_pow(3, (n / 3 - 1)) % mod;
  } else {
    return 2 * quick_pow(3, n / 3) % mod;
  }
}

int main() {
  long long n;
  // for (int i = 1; i <= 10; i++) cout << getans(i) << endl;
  cin>>n;
  cout<<getans(n)<<endl;
}
