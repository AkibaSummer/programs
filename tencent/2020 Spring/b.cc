#pragma GCC O(3)
#include <math.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
#define int long long

#define endl "\n"
double sqr(double n) { return n * n; }
double dist(pair<double, double> a, pair<double, double> b) {
  return sqrt(sqr(a.first - b.first) + sqr(a.second - b.second));
}

const double eps = 1e-7;

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    double ans = 2e9;
    cin >> n;
    vector<pair<double, double>> a(n), b(n);
    vector<pair<pair<double, double>, int>> c;
    c.reserve(2 * n);
    for (auto &i : a) {
      cin >> i.first >> i.second;
      c.push_back({i, 1});
    }
    for (auto &i : b) {
      cin >> i.first >> i.second;
      c.push_back({i, 2});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // vector<int> ax(n), ay(n), bx(n), by(n);
    // for (int i=0;i<n;i++){
    //   ax[i]=a[i].first;
    //   ay[i]=a[i].second;
    //   bx[i]=b[i].first;
    //   by[i]=b[i].second;
    // }
    sort(c.begin(), c.end());
    for (auto &ii : c) {
      auto i = ii.first;
      if (ii.second == 1) {
        int pos = lower_bound(b.begin(), b.end(),
                              pair<double, double>(i.first - ans - eps, -1e9)) -
                  b.begin();
        while (pos < n && b[pos].first - eps <= i.first) {
          pos = lower_bound(
                    b.begin(), b.end(),
                    pair<double, double>(
                        b[pos].first - eps,
                        i.second - eps -
                            sqrt(sqr(ans) - sqr(b[pos].first - i.first)))) -
                b.begin();
          if (pos == n) break;
          for (int j = pos; dist(i, b[j]) - eps <= ans; j++) {
            ans = min(ans, dist(i, b[j]));
          }
          pos = lower_bound(b.begin(), b.end(),
                            pair<double, double>(b[pos].first + 0.5, -1e9)) -
                b.begin();
        }
      } else {
        int pos = lower_bound(a.begin(), a.end(),
                              pair<double, double>(i.first - ans - eps, -1e9)) -
                  a.begin();
        while (pos < n && a[pos].first - eps <= i.first) {
          pos = lower_bound(
                    a.begin(), a.end(),
                    pair<double, double>(
                        a[pos].first - eps,
                        i.second - eps -
                            sqrt(sqr(ans) - sqr(a[pos].first - i.first)))) -
                a.begin();
          if (pos == n) break;
          for (int j = pos; dist(i, a[j]) - eps <= ans; j++) {
            ans = min(ans, dist(i, a[j]));
          }
          pos = lower_bound(a.begin(), a.end(),
                            pair<double, double>(a[pos].first + 0.5, -1e9)) -
                a.begin();
        }
      }
    }
    cout << fixed << setprecision(3) << ans << endl;
  }
}