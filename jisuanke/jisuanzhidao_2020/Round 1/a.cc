#pragma optimize O(3)

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int judge(vector<string> &vec, char type) {
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 25; j++) {
      if (vec[i][j] == type) {
        int q = 0, w = 0;
        for (q = 1; q <= 5; q++) {
          if (j + q >= 25 || vec[i][j + q] != type) {
            break;
          }
        }
        for (w = 1; w <= 5; w++) {
          if (j - w < 0 || vec[i][j - w] != type) {
            break;
          }
        }
        if (q + w + 1 - 2 >= 5) {
          return 1;
        }

        for (q = 1; q <= 5; q++) {
          if (i + q >= 25 || j + q >= 25 || vec[i + q][j + q] != type) {
            break;
          }
        }
        for (w = 1; w <= 5; w++) {
          if (i - w < 0 || j - w < 0 || vec[i - w][j - w] != type) {
            break;
          }
        }
        if (q + w + 1 - 2 >= 5) {
          return 1;
        }

        for (q = 1; q <= 5; q++) {
          if (i - q < 0 || j + q >= 25 || vec[i - q][j + q] != type) {
            break;
          }
        }
        for (w = 1; w <= 5; w++) {
          if (i + w >= 25 || j - w < 0 || vec[i + w][j - w] != type) {
            break;
          }
        }
        if (q + w + 1 - 2 >= 5) {
          return 1;
        }

        for (q = 1; q <= 5; q++) {
          if (i + q >= 25 || vec[i + q][j] != type) {
            break;
          }
        }
        for (w = 1; w <= 5; w++) {
          if (i - w < 0 || vec[i - w][j] != type) {
            break;
          }
        }
        if (q + w + 1 - 2 >= 5) {
          return 1;
        }
      }
    }
  }
  return 0;
}

int main() {
  vector<string> vec(25);
  for (auto &i : vec) {
    cin >> i;
  }
  int b = 0, w = 0;
  for (auto &i : vec) {
    for (auto &j : i) {
      if (j == 'x') {
        b++;
      } else if (j == 'o') {
        w++;
      }
    }
  }

  vector<pair<int, int>> ans;
  if (b == w) {  // next:black;

    for (int i = 0; i < 25; i++) {
      for (int j = 0; j < 25; j++) {
        if (vec[i][j] == '.') {
          vec[i][j] = 'x';
          if (judge(vec, 'x')) {
            ans.push_back({i, j});
          }
          vec[i][j] = '.';
        }
      }
    }
  } else {  // next:white;
    for (int i = 0; i < 25; i++) {
      for (int j = 0; j < 25; j++) {
        if (vec[i][j] == '.') {
          vec[i][j] = 'o';
          if (judge(vec, 'o')) {
            ans.push_back({i, j});
          }
          vec[i][j] = '.';
        }
      }
    }
  }
  if (ans.empty()) {
    cout << "tie" << endl;
  }
  for (auto &i : ans) {
    cout << i.first << ' ' << i.second << endl;
  }
}