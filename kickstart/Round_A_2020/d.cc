#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define int long long
const int maxn = 3e6 + 5;
int tree[maxn][30];
int sum[maxn];
int deep[maxn];
int flag[maxn];
int tot;
void insert_(string str) {
  int len = str.length();
  int root = 0;
  for (int i = 0; i < len; i++) {
    int id = str[i] - 'A';
    if (!tree[root][id]) tree[root][id] = ++tot;
    sum[tree[root][id]]++;
    root = tree[root][id];
    deep[root] = i + 1;
  }
  flag[root] += 1;
}

void init() {
  for (int i = 0; i <= tot; i++) {
    sum[i] = 0;
    deep[i] = 0;
    flag[i] = 0;
    memset(tree[i], 0, sizeof(tree[i]));
  }
  tot = 0;
}

void slove() {
  init();
  int n, k;
  cin >> n >> k;
  vector<string> input(n);
  for (auto &i : input) {
    cin >> i;
    insert_(i);
  }
  vector<pair<int, int>> point(tot + 1);
  for (int i = 0; i <= tot; i++) {
    point[i] = {deep[i], i};
  }
  int ans = 0;
  sort(point.begin(), point.end(), greater<pair<int, int>>());
  // cerr << point.size() << endl;
  for (auto &i : point) {
    int now = i.second;
    sum[now] = flag[now];
    for (int j = 0; j < 30; j++) {
      sum[now] += sum[tree[now][j]];
    }
    while (sum[now] >= k) {
      ans += i.first;
      sum[now] -= k;
      // cout<<ans<<endl;
    }
  }
  if (sum[0] != 0) exit(-1);
  cout << ans << endl;
}
int32_t main() {
  fast;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    slove();
  }
}