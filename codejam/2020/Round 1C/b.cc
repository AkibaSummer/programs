#pragma GCC optimize(3)
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

int error(int i = 0) { return error(i + 1); }
void slove() {
  int u;
  cin >> u;
  map<char, int> input;
  vector<char> ans(10);
  set<char> setsall, setfirst;

  for (int i = 1; i <= 10000; i++) {
    long long tmp;
    string s;
    cin >> tmp >> s;
    if (s.length() == u) input[s[0]]++;
    setfirst.insert(s[0]);
    for (auto &j : s) {
      setsall.insert(j);
    }
  }
  // if (input.size() != 9) {
  //   error();
  // }
  for (auto &i : setsall) {
    if (setfirst.count(i) == 0) {
      ans[0] = i;
    }
  }
  vector<pair<int, char>> cnt2;
  for (auto &i : input) {
    cnt2.push_back({i.second, i.first});
  }
  sort(cnt2.begin(), cnt2.end());
  for (int i = 0; i < 9; i++) {
    ans[9 - i] = cnt2[i].second;
  }
  for (auto &i : ans) {
    cout << i;
  }
  cout << endl;
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