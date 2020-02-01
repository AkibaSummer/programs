#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

pair<long long, long long> solve1(long long n) {
  if (n == 1)
    return {1, 1};
  else {
    auto ret = solve1(n / 2);
    if (n % 2) {
      return {ret.first + ret.second, ret.second};
    } else
      return {ret.first, ret.first + ret.second};
  }
}

long long solve2(pair<long long, long long> n) {
  if (n.first == n.second)
    return 1;
  else {
    if (n.first > n.second) {
      return solve2({n.first - n.second, n.second}) * 2 + 1;
    } else {
      return solve2({n.first, n.second - n.first}) * 2;
    }
  }
}

void solve() {
  int type;
  cin >> type;
  if (type == 1) {
    long long n;
    cin >> n;
    auto ans = solve1(n);
    cout << ans.first << ' ' << ans.second << endl;
  } else {
    long long p, q;
    cin >> p >> q;
    cout << solve2({p, q}) << endl;
  }
}
int main() {
  fast;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}