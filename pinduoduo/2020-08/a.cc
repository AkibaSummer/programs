#pragma GCC optimize(3)
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

int main() {
  int k, n;
  cin >> k >> n;
  int dst = k;
  int num = 0;
  if (dst == 0) {
    cout << "paradox" << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int tmp;
    cin >> tmp;
    if (tmp == dst) {
      dst = 0;
      if (i == n) break;
      cout << "paradox" << endl;
      return 0;
    } else if (dst > tmp) {
      dst -= tmp;
    } else {
      dst = tmp - dst;
      num++;
    }
  }
  cout << dst << ' ' << num << endl;
}