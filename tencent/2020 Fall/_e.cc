#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

void output(vector<pair<char, int>> input, int n) {
  cout << endl;
  for (auto &i : input) {
    cout << i.first << ' ';
  }
  cout << endl;
  for (auto &i : input) {
    cout << i.second << ' ';
  }
  cout << endl;
}

int slove1(vector<pair<char, int>> input, int n) {
  int ans = 0;
  for (int i = 0; i < 2 * n; i++) {
    int pos = -1;
    int minn = 10 * n;
    for (int j = i; j < 2 * n; j++) {
      if (input[j].first == input[i].first && input[j].second < minn) {
        minn = input[j].second;
        pos = j;
      }
    }
    if (pos == i) {
      continue;
    }

    for (int j = pos - 1; j >= i; j--) {
      swap(input[j], input[j + 1]);
      ans++;
    }
  }
  return ans;
}

int slove2(vector<pair<char, int>> input, int n) {
  int ans = 0;
  for (int i = 0; i < 2 * n; i++) {
    int posr = -1, minr = 10 * n, posb = -1, minb = 10 * n;
    for (int j = i; j < 2 * n; j++) {
      if (input[j].first == 'R' && input[j].second < minr) {
        minr = input[j].second;
        posr = j;
      }
      if (input[j].first == 'B' && input[j].second < minb) {
        minb = input[j].second;
        posb = j;
      }
    }
    if (posr == -1) {
      for (int j = posb - 1; j >= i; j--) {
        swap(input[j], input[j + 1]);
        ans++;
      }
    } else if (posb == -1) {
      for (int j = posr - 1; j >= i; j--) {
        swap(input[j], input[j + 1]);
        ans++;
      }
    } else {
      for (int j = min(posr, posb) - 1; j >= i; j--) {
        swap(input[j], input[j + 1]);
        ans++;
      }
    }
  }
  return ans;
}

int slove3(vector<pair<char, int>> input, int n) {
  int ans = 0;
  for (int i = 2 * n - 1; i >= 0; i--) {
    int posr = -1, minr = 0, posb = -1, minb = 0;
    for (int j = i; j >= 0; j--) {
      if (input[j].first == 'R' && input[j].second > minr) {
        minr = input[j].second;
        posr = j;
      }
      if (input[j].first == 'B' && input[j].second > minb) {
        minb = input[j].second;
        posb = j;
      }
    }
    if (posr == -1) {
      for (int j = posb; j < i; j++) {
        swap(input[j], input[j + 1]);
        ans++;
      }
    } else if (posb == -1) {
      for (int j = posr; j < i; j++) {
        swap(input[j], input[j + 1]);
        ans++;
      }
    } else {
      for (int j = min(posr, posb); j < i; j++) {
        swap(input[j], input[j + 1]);
        ans++;
      }
    }
  }
  return ans;
}

int slove4(vector<pair<char, int>> input, int n) {
  int ans = 0, nowr = 1, nowb = 1;
  for (int i = 0; i < 2 * n; i++) {
    int next = -1;
    for (int j = i; j < 2 * n; j++) {
      if (input[j].first == 'R' && input[j].second == nowr) {
        next = j;
        nowr++;
        break;
      }
      if (input[j].first == 'B' && input[j].second == nowb) {
        next = j;
        nowb++;
        break;
      }
    }
    for (int j = next - 1; j >= i; j--) {
      swap(input[j], input[j + 1]);
      ans++;
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<pair<char, int>> input(n * 2);
  string s;
  cin >> s;
  for (int i = 0; i < 2 * n; i++) {
    input[i].first = s[i];
  }
  for (auto &i : input) {
    cin >> i.second;
  }

  cout << min(slove1(input, n),
              min(slove2(input, n), min(slove3(input, n), slove4(input, n))))
       << endl;
}