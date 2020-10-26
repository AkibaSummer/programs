#include <bits/stdc++.h>
using namespace std;
int main() {
  string input;
  cin >> input;
  map<int, int> maps, maps1;
  for (auto &i : input) {
    maps[i]++;
  }
  string s;
  map<string, int> answer;
  int l = 0;
  for (int i = 0; i < input.length(); i++) {
    maps1[input[i]]++;
    s.push_back(input[i]);
    while (maps1.size() == maps.size()) {
      answer[s] = l;
      maps1[input[l]]--;
      if (maps1[input[l]] == 0) {
        maps1.erase(input[l]);
      }
      l++;
      s = s.substr(1);
    }
  }
  cout << answer.begin()->second << ' ' << answer.begin()->first.length()
       << endl;
  // cout << answer.begin()->first << endl;
}