#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, nn;
    cin >> n;
    nn = n;
    map<int, int> maps;
    for (int i = 2; i <= sqrt(n); i++) {
      while (n % i == 0) {
        maps[i]++;
        n /= i;
      }
    }
    if (n != 1) {
      maps[n]++;
    }
    int maxx = -1;
    for (auto &i : maps) {
      if (i.second > maps[maxx]) {
        maxx = i.first;
      }
    }
    cout<<maps[maxx]<<endl;
    for (int i = 1; i < maps[maxx]; i++) {
      cout << maxx << ' ';
      nn /= maxx;
    }
    cout << nn << endl;
  }
}