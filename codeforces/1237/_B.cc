#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main() {
  int n;
  cin >> n;
  vector<int> input1(n), input2(n);
  vector<int> pos(n + 2), mov(n + 2);
  for (auto &i : input1) cin >> i;
  for (auto &i : input2) cin >> i;
  for (int i = 0; i < n; i++) {
    pos[input1[i]] = i;
  }
  int tmp = 0, ans = 0;
  // for (auto &i:pos)cerr<<i<<' ';
  // cerr<<endl;
  for (int i = 0; i < n; i++) {
    if (pos[input2[i]] > i - tmp) {
      ans++;
      tmp++;
      mov[pos[input2[i]]]--;
      tmp += mov[i];
      cerr << i << ' ' << tmp << endl;
    }
  }
  cout << ans << endl;
}