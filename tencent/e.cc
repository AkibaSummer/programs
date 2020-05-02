#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

long long getans(long long x, long long k) {
  if ((1ll << k) > x) {
    return -1;
  } else {
    long long ret = getans(x >> 1, k);
    if (ret == -1) {
      return x >> 1;
    } else {
      return ret;
    }
  }
}

int main() {
  int q;
  cin >> q;
  while (q--) {
    long long x, k;
    cin >> x >> k;
    cout << getans(x, k) << endl;
  }
}