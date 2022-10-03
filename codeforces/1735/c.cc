#include <bits/stdc++.h>
using namespace std;

bool check(vector<char> &v, char c) {
  char cc = v[c];
  int cnt = 0;
  while (v[cc] != 0 && v[cc] != c) {
    cc = v[cc];
    cnt++;
  }
  if (cnt == 25) {
    return false;
  }
  if (v[cc] == c) {
    return true;
  }
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> v(126, 0);
    vector<bool> t(126, 0);
    for (auto &i : s) {
      if (v[i] != 0) {
        continue;
      }
      for (char c = 'a'; c <= 'z'; c++) {
        if (c == i) {
          continue;
        }
        if (t[c]) {
          continue;
        }
        v[i] = c;
        if (check(v, c)) {
          continue;
        } else {
          t[c] = 1;
          break;
        }
      }
    }
    for (auto &i : s) {
      cout << v[i];
    }
    cout << endl;
  }
}