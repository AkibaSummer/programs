#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  vector<vector<int>> mov = {{1, 3},    {0, 2, 4},    {1, 5},
                             {0, 4, 6}, {1, 3, 5, 7}, {2, 4, 8},
                             {3, 7},    {4, 6, 8},    {5, 7}};
  vector<int> source;
  vector<int> target;
  int getnum(vector<int> now) {
    int ret = 0;
    for (int i = 0; i < 9; i++)
      if (now[i] != target[i]) ret++;
    return ret;
  }

 public:
  map<vector<int>, vector<int>> pre;

  void input() {
    source.resize(9);
    target.resize(9);
    cout << "Please input source layout:" << endl;
    for (auto &i : source) cin >> i;
    cout << "Please input target layout:" << endl;
    for (auto &i : target) cin >> i;
    pre.clear();
    pre[source] = vector<int>();
  }

  void getans() {
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>,
                   greater<pair<int, vector<int>>>>
        que;
    que.push({getnum(source), source});
    int isgetans = 0;
    while (!que.empty()) {
      auto top = que.top();
      que.pop();
      top.first = top.first - getnum(top.second);
      auto zero_pos = [&]() {
        for (int i = 0; i < 9; i++)
          if (top.second[i] == 0) return i;
      }();
      for (auto &i : mov[zero_pos]) {
        auto now = top;
        top.first += getnum(top.second);
        swap(now.second[zero_pos], now.second[i]);
        if (!pre.count(now.second)) {
          pre[now.second] = top.second;
          que.push(now);
        }
        if (now.second == target) isgetans = 1;
      }
      if (isgetans) break;
    }
  }
  void printans() {
    cout << "Solution is:" << endl;
    int count = 0;
    vector<vector<int>> vec;
    auto now = target;
    while (now != vector<int>()) {
      vec.push_back(now);
      now = pre[now];
    }
    for (auto &i : vec) {
      cout << "step " << count++ << endl;
      cout << i[0] << ' ' << i[1] << ' ' << i[2] << endl;
      cout << i[3] << ' ' << i[4] << ' ' << i[5] << endl;
      cout << i[6] << ' ' << i[7] << ' ' << i[8] << endl;
      cout << endl;
    }
  }
};
int main() {
  Solution solution;
  solution.input();
  solution.getans();
  solution.printans();
}
/*
0 1 2
3 4 5
6 7 8

6 7 8
3 4 5
0 1 2
*/