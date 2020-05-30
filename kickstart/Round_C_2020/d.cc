//#pragma GCC optimize(3)
#include <string.h>

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

#define int long long
const int maxn = 2e5 + 5;
int n, q;
int input[maxn];
int even[maxn], evenl[maxn], event[maxn], evenlt[maxn];
int odd[maxn], oddl[maxn], oddt[maxn], oddlt[maxn];
int Lowbit(int x) { return x & (-x); }
void update(int i, int x, int c[]) {
  while (i <= n) {
    c[i] += x;
    i += Lowbit(i);
  }
}

int sum(int x, int c[]) {
  int sum = 0;
  while (x > 0) {
    sum += c[x];
    x -= Lowbit(x);
  }
  return sum;
}

int Getsum(int x1, int x2, int c[]) { return sum(x2, c) - sum(x1 - 1, c); }

void init() {
  memset(input, 0, (n + 5) * sizeof(int));
  memset(odd, 0, (n + 5) * sizeof(int));
  memset(oddl, 0, (n + 5) * sizeof(int));
  memset(oddt, 0, (n + 5) * sizeof(int));
  memset(oddlt, 0, (n + 5) * sizeof(int));
  memset(even, 0, (n + 5) * sizeof(int));
  memset(evenl, 0, (n + 5) * sizeof(int));
  memset(event, 0, (n + 5) * sizeof(int));
  memset(evenlt, 0, (n + 5) * sizeof(int));
}

void slove() {
  cin >> n >> q;
  init();
  for (int i = 1; i <= n; i++) {
    cin >> input[i];
    if (i % 2) {
      odd[i] = input[i];
      oddl[i] = input[i] * i;
      update(i, odd[i], oddt);
      update(i, oddl[i], oddlt);
    } else {
      even[i] = input[i];
      evenl[i] = input[i] * i;
      update(i, even[i], event);
      update(i, evenl[i], evenlt);
    }
  }
  int ans = 0;
  while (q--) {
    char c;
    cin >> c;
    if (c == 'Q') {
      int l, r;
      cin >> l >> r;
      auto e = Getsum(l, r, evenlt) - Getsum(l, r, event) * (l - 1);
      auto o = Getsum(l, r, oddlt) - Getsum(l, r, oddt) * (l - 1);
      if (l % 2) {
        ans += o - e;
      } else {
        ans += e - o;
      }
    } else {
      int x, v;
      cin >> x >> v;
      if (x % 2) {
        update(x, v - odd[x], oddt);
        update(x, x * v - oddl[x], oddlt);
        odd[x] = v;
        oddl[x] = x * v;
      } else {
        update(x, v - even[x], event);
        update(x, x * v - evenl[x], evenlt);
        even[x] = v;
        evenl[x] = x * v;
      }
    }
  }
  cout << ans << endl;
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