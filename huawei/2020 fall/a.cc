#include <bits/stdc++.h>
using namespace std;

void getHash1(map<string, int>& maps, string s, int pos) {
  string tmps = s.substr(pos, 1);
  maps[tmps] = tmps.length();
  for (int i = 1;; i++) {
    if (i > pos || i + pos >= s.length()) {
      break;
    }
    if (s[pos - i] != s[pos + i]) {
      break;
    }
    tmps = s[pos - i] + tmps + s[pos + i];
    maps[tmps] = tmps.length();
  }
  return;
}
void getHash2(map<string, int>& maps, string s, int pos) {
  string tmps = s.substr(pos, 2);
  maps[tmps] = tmps.length();
  for (int i = 1;; i++) {
    if (i > pos || i + pos + 1 >= s.length()) {
      break;
    }
    if (s[pos - i] != s[pos + i]) {
      break;
    }
    tmps = s[pos - i] + tmps + s[pos + i + 1];
    maps[tmps] = tmps.length();
  }
  return;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  map<string, int> maps1, maps2;

  for (int i = 0; i < s1.length(); i++) {
    getHash1(maps1, s1, i);
    if (i < s1.length() - 1 && s1[i] == s1[i + 1]) {
      getHash2(maps1, s1, i);
    }
  }

  for (int i = 0; i < s2.length(); i++) {
    getHash1(maps2, s2, i);
    if (i < s2.length() - 1 && s2[i] == s2[i + 1]) {
      getHash2(maps2, s2, i);
    }
  }

  // for (auto& i : maps1) {
  //   cerr << i.first << ' ' << i.second << endl;
  // }

  int ans = 0;
  for (auto& i : maps1) {
    if (maps2.count(i.first)) {
      ans = max(ans, i.second);
    }
  }
  cout << ans << endl;
}