#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> input(n);
  for (auto &i : input) {
    cin >> i;
  }
  int minn = input[0];
  int maxx = input[0];
  for (auto &i : input) {
    minn = min(minn, i);
    maxx = max(maxx, i);
  }
  int l = maxx - m;
  int r = minn + m;
  if (l > r) {
    cout << -1 << endl;
  } else {
    cout << l << ' ' << r << endl;
  }
}