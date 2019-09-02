#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define lowbit(x) ((x) & (-x))

const int M = 1000005;

long long b[M + 50];

void add(int a, int x) {
  while (a <= M) {
    b[a] += x;
    a += lowbit(a);
  }
  return;
}

long long sum(int a) {
  long long ret = 0;
  while (a) {
    ret += b[a];
    a -= lowbit(a);
  }
  return ret;
}

const int N = 500050;

using pii = pair<int, int>;

struct ss {
  pii x;
  long long t;
  bool operator<(const ss &b) const { return x < b.x; }
};

// bool cmp(const ss &x, const ss &y) { return x.x < y.x; }
long long ret[N];
void solve(vector<ss> &v) {
  sort(v.begin(), v.end());
  memset(b, 0, sizeof(b[0]) * (M + 1));
  for (int i = 0; i < v.size(); i++) {
    add(v[i].x.second, v[i].t);
    ret[i] = sum(v[i].x.second);
    // cout << "[" << v[i].x.first << " " << v[i].x.second << "]" << ret[i]
    //      << endl;
  }
}

auto getreter(vector<ss> &v) {
  return [&](const ss &x) -> long long {
    return ret[lower_bound(v.begin(), v.end(), x) - v.begin()];
  };
}

long long getans(long long n, int x, int y) {
  x--;
  y--;
  auto tmp = n / 2 + 1;
  auto range = max(abs(x - tmp), abs(y - tmp));
  long long pre = 0;
  if (range * 2 != n - 1) {
    pre = (range * 2 + 2 + n - 1) * 4 * (n - 1 - range * 2) / 2 / 2;
  }
  long long ret = 0;
  // cout<<pre<<' ';
  if (x == tmp + range)
    ret = pre + x - y + 1;
  else if (y == tmp - range)
    ret = pre + range * 2 + (tmp + range) - x + 1;
  else if (x == tmp - range)
    ret = pre + range * 2 * 2 + y - x + 1;
  else
    ret = pre + range * 2 * 3 + x - (tmp - range) + 1;
  int ans = 0;
  while (ret) {
    ans += ret % 10;
    ret /= 10;
  }
  return ans;
}

struct query {
  int x1, x2, y1, y2;
  int ans = 0;
};

void slove() {
  int n, m, p;
  cin >> n >> m >> p;
  vector<ss> input(m), points;
  vector<query> querys(p);
  for (auto &i : input) {
    cin >> i.x.first >> i.x.second;
    i.x.first++;
    i.x.second++;
    i.t = getans(n, i.x.first, i.x.second);
    // cout << i.t << endl;
  }
  input.reserve(m + 4 * p);
  for (auto &i : querys) {
    cin >> i.x1 >> i.y1 >> i.x2 >> i.y2;
    i.x1++;
    i.x2++;
    i.y1++;
    i.y2++;
    input.push_back({{i.x1 - 1, i.y1 - 1}, 0});
    input.push_back({{i.x1 - 1, i.y2}, 0});
    input.push_back({{i.x2, i.y1 - 1}, 0});
    input.push_back({{i.x2, i.y2}, 0});
  }
  sort(input.begin(), input.end());
  points.reserve(input.size());
  for (auto &i : input) {
    if (points.empty())
      points.push_back(i);
    else {
      if (points.back().x == i.x) {
        points.back().t += i.t;
      } else
        points.push_back(i);
    }
  }

  // for (auto &i : points) {
  //   cout << "[" << i.x.first << ' ' << i.x.second << "] " << i.t << endl;
  // }

  solve(points);
  auto reter = getreter(points);
  for (auto &i : querys) {
    int ans = 0;
    // cout << reter({{i.x2, i.y2}, 0}) << "+" << reter({{i.x1 - 1, i.y1 - 1},
    // 0})
    //      << "-" << reter({{i.x1 - 1, i.y2}, 0}) << "-"
    //      << reter({{i.x2, i.y1 - 1}, 0}) << endl;
    ans += reter({{i.x2, i.y2}, 0});
    ans += reter({{i.x1 - 1, i.y1 - 1}, 0});
    ans -= reter({{i.x1 - 1, i.y2}, 0});
    ans -= reter({{i.x2, i.y1 - 1}, 0});
    cout << ans << endl;
  }
}

int main() {
  fast;
  int tt;
  cin >> tt;
  for (int ii = 1; ii <= tt; ii++) {
    // int n, x, y;
    // cin >> n >> x >> y;
    // cout << getans(n, x, y) << endl;
    slove();
  }
}
