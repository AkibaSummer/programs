#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)

int slove() {
  int n, m;
  // cin >> n >> m;
  scanf("%d%d", &n, &m);
  vector<int> input(2 * m);
  for (int i = 0; i < m; i++) {
    int a, b;
    // cin >> a >> b;
    scanf("%d%d", &a, &b);
    input[i * 2] = a;
    input[i * 2 + 1] = b + 1;
  }
  sort(input.begin(), input.end());
  int stat = 0, pre = -1;
  int ans = 0;
  for (auto &i : input) {
    ans += stat * (i - pre);
    stat = 1 - stat;
    pre = i;
  }
  if (stat)
    ans += n - pre + 1;
  return ans;
}

int main() {
  // fast;
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: %d\n", i, slove());
    // cout << "Case #" << i << ": " << slove() << endl;
  }
}