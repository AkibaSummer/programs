#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main() {
  int t = 100;
  int n = 10000;
  cout << t << endl;
  for (int i = 1; i <= t; i++) {
    cout << n << endl;
    for (int j = 1; j <= n; j++) {
      cout << rand() % (i*10000) << ' ' << rand() % (i*10000) << endl;
    }
  }
}
