#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  int n;
  vector<vector<int>> pm;
  vector<vector<int>> pw;
  vector<int> m;
  vector<int> w;

  int find_fir(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++)
      if (vec[i] == -1) return i;
    return -1;
  }

  bool check(vector<int> &vec, int pos1, int pos2) {
    for (int i = 0; i < vec.size(); i++) {
      if (vec[i] == pos1)
        return true;
      else if (vec[i] == pos2)
        return false;
    }
    return false;
  }

 public:
  void slove() {
    int mpos, wpow;
    int pos = 0;
    for (int i = 0; i < n; i++) {
      m.push_back(-1);
      w.push_back(-1);
    }
    while ((mpos = find_fir(m)) >= 0) {
      pos = 0;
      while (pos < n) {
        wpow = pm[mpos][pos];
        if (w[wpow] == -1) {
          m[mpos] = wpow;
          w[wpow] = mpos;
          break;
        } else if (check(pw[wpow], mpos, w[wpow])) {
          m[w[wpow]] = -1;
          w[wpow] = mpos;
          m[mpos] = wpow;
          break;
        } else
          pos++;
      }
    }
  }

  void input() {
    cin >> n;
    pm.resize(n);
    for (auto &i : pm) {
      i.resize(n);
      for (auto &j : i) {
        cin >> j;
      }
    }
    pw.resize(n);
    for (auto &i : pw) {
      i.resize(n);
      for (auto &j : i) {
        cin >> j;
      }
    }
  }

  void output() {
    for (int i = 0; i < n; i++) {
      cout << "Man:" << i << " <-> Woman:" << m[i] << endl;
    }
  }
};

int main() {
  Solution solution;
  solution.input();
  solution.slove();
  solution.output();
}
/*
10
1 4 3 6 2 5 8 7 9 0
2 1 0 3 4 8 5 9 7 6
4 3 8 9 0 2 1 7 6 5
2 7 6 1 4 3 8 0 9 5
5 3 8 4 2 0 7 6 1 9
5 0 1 7 2 8 9 4 6 3
6 2 9 8 0 7 5 1 4 3
9 7 1 8 0 2 5 6 3 4
8 0 5 9 6 7 1 2 4 3
7 9 1 6 2 0 5 8 4 3

3 5 0 6 9 4 8 7 2 1
0 1 3 2 7 8 5 9 4 6
1 0 7 9 3 2 5 8 6 4
2 0 6 3 4 1 5 7 9 8
5 6 8 3 2 0 9 4 1 7
3 0 1 7 9 8 2 4 6 5
6 2 7 8 0 9 4 1 5 3
9 3 1 2 0 7 5 6 8 4
4 1 5 9 6 7 0 2 8 3
6 0 1 7 2 9 5 8 4 3

*/