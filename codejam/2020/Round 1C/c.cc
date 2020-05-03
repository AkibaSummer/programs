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
typedef long long ll;

int error(int i = 0) { return error(i + 1); }
void slove() {
  ll n, d;
  cin >> n >> d;
  vector<ll> a(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());
  ll ans = d - 1;
  for (ll ii = 1; ii <= d; ii++) {
    for (auto &i : a) i *= ii;
    for (auto &i : a) {
      ll now = i / ii;
      ll may = 0, last = d, cnt = 0;
      ll finish = 0;
      int beg = lower_bound(a.begin(), a.end(), now) - a.begin();
      for (int jj = beg; jj < a.size(); jj++) {
        auto &j = a[jj];
        if (j / now == last && j % now == 0) {
          cnt += last - 1;
          last = 0;
          finish = 1;
          break;
        }
        if (j / now > last) {
          cnt += last;
          last = 0;
          finish = 1;
          break;
        }
        if (j % now == 0) {
          cnt += (j / now) - 1;
          last -= j / now;
          continue;
        }
        may += j / now;
      }
      if (finish) {
        ans = min(ans, cnt);
      } else {
        if (last <= may) {
          cnt += last;
          ans = min(ans, cnt);
        }
      }
    }
    for (auto &i : a) i /= ii;
  }
  cout << ans << endl;
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