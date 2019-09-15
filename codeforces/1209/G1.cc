#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define endl "\n"

int getans(int l, int r, vector<int> &a) {
  unordered_map<int, int> mp;
  for (int i = l; i <= r; i++)
    mp[a[i]]++;
  int maxx = 0;
  for (auto &i : mp) {
    maxx = max(maxx, i.second);
  }
  return r - l + 1 - maxx;
}
void slove() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 5);
  vector<vector<int>> V(200005);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    V[a[i]].push_back(i);
  }
  for (int i = 1; i <= 200000; i++)
    sort(V[i].begin(), V[i].end());
  int l_ = 1, r_ = -1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    r_ = max(r_, V[a[i]].back());
    if (r_ == i) {
      ans += getans(l_, r_, a);
      l_ = r_ = i + 1;
    }
  }
  if (l_ <= n)
    ans += getans(l_, n, a);
  cout << ans << endl;
}

int main() {
  fast;
  int t;
  // cin>>t;
  t = 1;
  while (t--) {
    slove();
  }
}