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

int main() {
  fast;
  int t = 100000;
  cout << t << endl;
  for (int i = 1; i <= t; i++) {
    if (rand() % 2) {
      cout << 1 << ' ' << ((long long)rand() << 32) + rand() << endl;
    } else {
      auto out = solve1(((long long)rand() << 32) + rand());
      cout << 2 << ' ' << out.first << ' ' << out.second << ' ' << endl;
    }
  }
}