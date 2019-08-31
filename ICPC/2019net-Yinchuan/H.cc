#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.second * b.first < a.first * b.second;
}

vector<int> counter;
void slove() {
  int n;
  cin >> n;
  vector<pair<int, int>> input(n);
  for (auto &i : input)
    cin >> i.first >> i.second;
  for (auto &i : input) {
    i.first = lower_bound(counter.begin(), counter.end(), i.first) -
              counter.begin() + 1;
    // cerr<<i.first<<' ';
  }
  sort(input.begin(), input.end(), cmp);
  reverse(input.begin(), input.end());
  int ans = 0, sum = 0;
  for (auto &i : input) {
    sum += i.first;
    ans += sum * i.second;
  }
  cout << ans << endl;
}

signed main() {
  int tmp = 0;
  for (int i = 1; tmp <= 100000; i++) {
    tmp += i;
    counter.push_back(tmp);
  }
  counter.push_back(tmp);
  // for (auto &i:counter)cerr<<i<<' ';
  int t;
  cin >> t;
  for (int ii = 1; ii <= t; ii++) {
    cout << "Case #" << ii << ": ";
    slove();
  }
}