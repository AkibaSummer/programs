//#pragma GCC optimize(3)
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

void slove() {
  int a, b, c, n;
  cin >> n >> a >> b >> c;
  if (a + b - c > n) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    int other = n - (a + b - c);
    int aa = a - c;
    int bb = b - c;
    vector<int> output;
    if (n == 2 && a == 1 && b == 1) {
      cout << "IMPOSSIBLE" << endl;
      return;
    } else if (n == 1) {
      cout << 1 << endl;
      return;
    } else if (n == 2) {
      if (a == 2 && b == 2 && c == 2) {
        cout << 1 << ' ' << 1 << endl;
      } else if (a == 2 && c == 1 && b == 1) {
        cout << 1 << ' ' << 2 << endl;
      } else if (a == 1 && c == 1 && b == 2) {
        cout << 2 << " " << 1 << endl;
      } else {
        cout << "IMPOSSIBLE" << endl;
      }
      return;
    }
    if (max(max(a, b), c) == 1) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
    while (aa--) {
      output.push_back(2);
    }
    while (c--) {
      output.push_back(3);
    }
    while (bb--) {
      output.push_back(2);
    }
    for (int i = 0; i < output.size(); i++) {
      cout << output[i] << ' ';
      if (i == 0) {
        while (other--) {
          cout << 1 << " ";
        }
      }
    }

    cout << endl;
  }
}

int main() {
  fast;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    slove();
  }
}