#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

void slove() {
  int n, k, p;
  cin >> n >> k >> p;
  vector<int> value(p + 5);
  for (int i = 1; i <= n; i++) {
    vector<int> lines(k + 3);
    for (int j = 1; j <= k; j++) {
      cin >> lines[j];
      lines[j] += lines[j - 1];
    }
    // cerr<<"test"<<endl;
    for (int j = p; j >= 1; j--) {
      for (int e = j - 1; e >= max(0, j - k); e--) {
        // cerr<<j<<' '<<e<<endl;
        value[j] = max(value[j], value[e] + lines[j - e]);
      }
    }
    // for (int i=1;i<=p;i++){
    //   cerr<<value[i]<<' ';
    // }
    // cerr<<endl;
  }
  cout << value[p] << endl;
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