#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c;
  cin >> n >> c;
  vector<pair<int, int>> input(n);
  for (auto &i : input) {
    int w, v;
    cin >> w >> v;
    i.first = w;
    i.second = v;
  }
  vector<int> value(c + 5, 0xffffffff);
  vector<vector<pair<int, int>>> items(c + 5);
  value[0] = 0;
  int maxvalue = 0xffffffff, maxpos = -1;
  for (auto &i : input) {
    for (int j = c; j >= i.first; j--) {
      if (value[j - i.first] + i.second > value[j]) {
        value[j] = value[j - i.first] + i.second;
        if (maxvalue < value[j]) {
          maxvalue = value[j];
          maxpos = j;
        }
        items[j] = items[j - i.first];
        items[j].push_back(i);
      }
    }
  }
  cout << "Max value is:" << maxvalue << endl;
  cout << "The items selected are:" << endl;
  for (auto &i : items[maxpos]) {
    cout << "w:" << i.first << " v:" << i.second << endl;
  }
}
/*
5 10
2 6
2 3
6 5
5 4
4 6
*/