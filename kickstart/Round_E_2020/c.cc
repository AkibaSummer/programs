//#pragma GCC optimize(3)
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;
#define int long long
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

int Lowbit(int x) { return x & (-x); }

void update(int i, int x, vector<int> &c) {
  int n = c.size();
  while (i <= n) {
    c[i] += x;
    i += Lowbit(i);
  }
}

int sum(int x, vector<int> &c) {
  int sum = 0;
  while (x > 0) {
    sum += c[x];
    x -= Lowbit(x);
  }
  return sum;
}

int Getsum(int x1, int x2, vector<int> &c) {
  return sum(x2, c) - sum(x1 - 1, c);
}

void slove() {
  int n;
  cin >> n;
  vector<pair<int, int>> input(n + 1);
  vector<int> sums(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    auto &now = input[i];
    cin >> now.first >> now.second;
    sum += now.first;
    now.second += now.first;
    update(i, input[i].first, sums);
  }
  vector<pair<int, int>> ft(n + 1);
  for (int i = 1; i <= n; i++) {
    ft[i] = {input[i].second, i};
  }
  sort(ft.begin() + 1, ft.end());
  int ans = sum, ansn = 0;
  int minn = 0;
  int preposk = n;
  set<int> last;
  for (int i = 1; i < n; i++) {
    auto pos = lower_bound(ft.begin() + 1, ft.end(),
                           (pair<int, int>){sum, 0x3fffffffffffffffl});
    if (pos == ft.end()) {
      ans = -1;
      break;
    }
    int posk = pos - ft.begin();
    while (preposk >= posk) {
      last.insert(ft[preposk].second);
      preposk--;
    }
    if (last.empty()) {
      ans = -1;
      break;
    }
    int next = *last.begin();
    if (sum + Getsum(1, next - 1, sums) > ans) {
      ans = sum + Getsum(1, next - 1, sums);
      ansn = minn;
    }
    last.erase(last.begin());
    sum -= input[next].first;
    update(next, -input[next].first, sums);
    minn += 1;
  }
  if (ans == -1) {
    cout << minn << " "
         << "INDEFINITELY" << endl;
  } else {
    cout << ansn << " " << ans << endl;
  }
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