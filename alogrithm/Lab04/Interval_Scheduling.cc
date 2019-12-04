#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> input(n);
  for (auto &i : input) {
    cin >> i.first >> i.second;
  }
  sort(input.begin(), input.end(),
       [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
  int now_time = 0xffffffff;
  vector<pair<int, int>> ans;
  for (auto &i : input) {
    if (i.first >= now_time) {
      now_time = i.second;
      ans.push_back(i);
    }
  }
  cout << "Total tasks:" << ans.size() << endl;
  for (auto &i : ans) {
    cout << i.first << ' ' << i.second << endl;
  }
}
/*
8
1 6
1 4
3 5
3 8
4 7
5 9
6 10
8 11
*/