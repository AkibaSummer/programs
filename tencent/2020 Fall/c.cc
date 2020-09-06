#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
struct node {
  int val;
  node *next;
};
int main() {
  int n, k;
  cin >> n >> k;
  map<string, int> count;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    count[s]++;
  }
  map<int, vector<string>> strings;
  for (auto &i : count) {
    strings[i.second].push_back(i.first);
  }
  vector<pair<int, vector<string>>> vec;
  for (auto &i : strings) {
    vec.push_back(i);
  }
  sort(vec.begin(), vec.end());
  for (auto &i : vec) {
    sort(vec.begin(), vec.end());
  }
  int num = 0;
  int pos1 = vec.size() - 1;
  int pos2 = 0;
  while (num < k) {
    if (pos2 < vec[pos1].second.size()) {
      cout << vec[pos1].second[pos2] << " " << vec[pos1].first << endl;
      pos2++;
    } else {
      pos1--;
      pos2 = 0;
      cout << vec[pos1].second[pos2] << " " << vec[pos1].first << endl;
      pos2++;
    }
    num++;
  }
  num = 0;
  pos1 = 0;
  pos2 = 0;
  while (num < k) {
    if (pos2 < vec[pos1].second.size()) {
      cout << vec[pos1].second[pos2] << " " << vec[pos1].first << endl;
      pos2++;
    } else {
      pos1++;
      pos2 = 0;
      cout << vec[pos1].second[pos2] << " " << vec[pos1].first << endl;
      pos2++;
    }
    num++;
  }
}