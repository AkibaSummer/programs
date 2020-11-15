// #pragma GCC optimize(3)
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define int long long

pair<int, pair<int, int>> value(vector<pair<int, int>> input, int n) {
  int k = input.size();
  pair<int, pair<int, int>> answer = {0, {0, 0}};
  for (int i = 0; i < k; i++) {
    answer.first += abs(input[i].first - (n + i));
    answer.second.first += (input[i].first > (n + i));
    answer.second.second += (input[i].first < (n + i));
  }
  return answer;
}

void slove() {
  int n;
  cin >> n;
  vector<pair<int, int>> input(n);
  for (auto &i : input) {
    cin >> i.first >> i.second;
  }
  sort(input.begin(), input.end(),
       [&](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
  int mid = input[n / 2].second;
  int answer = 0;
  for (auto &i : input) {
    answer += abs(i.second - mid);
  }

  int l = -1e10;
  int r = 1e10;
  sort(input.begin(), input.end());
  int ans = 1e18;
  int flag = 0;
  while (r - l >= 1000) {
    int midVal = (r + l) / 2;
    auto mid = value(input, midVal);
    ans = min(ans, mid.first);
    if (mid.second.first == mid.second.second) {
      flag = 1;
      break;
    }
    if (mid.second.first < mid.second.second) {
      r = midVal;
    } else {
      l = midVal;
    }
  }
  if (!flag) {
    for (int i = l; i <= r; i++) {
      ans = min(ans, value(input, i).first);
    }
  }
  cout << ans + answer << endl;
}
signed main() {
  fast;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    slove();
  }
}