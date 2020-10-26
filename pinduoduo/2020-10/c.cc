#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  char c;
  vector<pair<char, int>> vec(n);
  for (auto &i : vec) {
    cin >> i.first >> i.second;
  }
  vector<pair<int, int>> trans(m);
  int bit = 0;
  for (auto &j : vec) {
    if (j.first == '|') {
      bit |= j.second;
    } else if (j.first == '&') {
      bit &= j.second;
    } else if (j.first == '^') {
      bit ^= j.second;
    }
  }
  for (int i = 0; i < m; i++) {
    trans[i].first = ((bit & (1 << i)) > 0);
  }
  for (int i = 0; i < m; i++) {
    int bit = 1 << i;
    for (auto &j : vec) {
      if (j.first == '|') {
        bit |= j.second;
      } else if (j.first == '&') {
        bit &= j.second;
      } else if (j.first == '^') {
        bit ^= j.second;
      }
    }
    trans[i].second = ((bit & (1 << i)) > 0);
  }
  int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
  for (int i = 0; i < m; i++) {
    if (trans[i].first == 0 && trans[i].second == 0) {
      ans1 |= 1 << i;
      ans2 |= 1 << i;
      ans3 |= 0 << i;
      ans4 |= 0 << i;
    }
    if (trans[i].first == 0 && trans[i].second == 1) {
      ans1 |= 1 << i;
      ans2 |= 1 << i;
      ans3 |= 1 << i;
      ans4 |= 0 << i;
    }
    if (trans[i].first == 1 && trans[i].second == 0) {
      ans1 |= 1 << i;
      ans2 |= 0 << i;
      ans3 |= 1 << i;
      ans4 |= 0 << i;
    }
    if (trans[i].first == 1 && trans[i].second == 1) {
      ans1 |= 1 << i;
      ans2 |= 1 << i;
      ans3 |= 1 << i;
      ans4 |= 1 << i;
    }
  }
  cout << 4 << endl;
  cout << "^ " << ans1 << endl;
  cout << "^ " << ans2 << endl;
  cout << "& " << ans3 << endl;
  cout << "| " << ans4 << endl;
}

// x | a | b = a | (a | b)
// x & b & c = x & (b & c)
// x ^ b ^ c = x ^ (b ^ c)

// x | b & c = x & c | (b & c)
// x | b ^ c = x | (b ^ c)
