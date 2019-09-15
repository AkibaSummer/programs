#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define endl "\n"
const int mod = 1000000007;

inline int seek(int x, vector<int> &fat) {
  return fat[x] == x ? x : fat[x] = seek(fat[x],fat);
}

void slove() {
  int n, k;
  cin >> n >> k;
  vector<int> fat(n);
  for (int i = 0; i < n; i++)
    fat[i] = i;
  int ans = 0;
  while (k--) {
    int a, b;
    cin >> a >> b;
    a--;b--;
    int fat1 = seek(a, fat);
    int fat2 = seek(b, fat);
    if (fat1 == fat2)
      ans++;
    fat[fat1] = fat2;
  }
  cout << ans << endl;
}

int main() {
  fast;
  int t;
  t = 1;
  while (t--) {
    slove();
  }
}
