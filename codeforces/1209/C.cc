#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define endl "\n"
const int mod = 1000000007;

void slove() {
  int n;
  cin >> n;
  vector<int> input(n), colored(n, 2);
  string s;
  cin >> s;
  for (int i = 0; i < n; i++)
    input[i] = s[i];
  int maxx = -1, maxxx = -1;
  for (int i = 0; i < n; i++) {
    maxxx = max(maxxx, input[i]);
    if (input[i] < maxxx) {
      colored[i] = 1;
      maxx = max(maxx, input[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (input[i] < maxx) {
      colored[i] = 1;
    }
  }
  vector<int> judge;
  for (int i = 0; i < n; i++) {
    if (colored[i] == 1)
      judge.push_back(input[i]);
  }
  for (int i = 0; i < n; i++) {
    if (colored[i] == 2)
      judge.push_back(input[i]);
  }
  // for (auto &i:judge)cout<<i-'0';
  // cout<<endl;
  for (int i = 1; i < n; i++) {
    if (judge[i] < judge[i - 1]) {
      cout << "-" << endl;
      return;
    }
  }
  for (auto &i : colored)
    cout << i;
  cout << endl;
}

int main() {
  // fast;
  int t;
  cin >> t;
  // t = 1;
  while (t--) {
    slove();
  }
}