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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> input(n);
    for (auto &i : input) cin >> i;
    if (input[0] + input[1] <= input[n - 1]) {
      cout << 1 << ' ' << 2 << ' ' << n << endl;
    } else {
      cout << -1 << endl;
    }
  }
}