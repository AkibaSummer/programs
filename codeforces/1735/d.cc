#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> input(n, vector<int>(k));
  for (auto &i : input) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  set<vector<int>> s;
  for (auto &i : input) {
    s.insert(i);
  }
  int ans = 0;
  for (int i = 0; i < input.size(); i++) {
    int count = 0;
    for (int j = 0; j < input.size(); j++) {
      vector<int> t(k);
      for (int l = 0; l < k; l++) {
        if (input[i][l] == input[j][l])
          t[l] = input[i][l];
        else
          t[l] = 3 - input[i][l] - input[j][l];
      }
      // for (auto &q : t) {
      //   cerr << int(q) << ' ';
      // }
      // cerr << endl;
      count += s.count(t);
    }
    count = count - 1;
    count = count / 2;
    ans = ans + count * (count - 1) / 2;
  }
  cout << ans << endl;
}