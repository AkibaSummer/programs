// #pragma GCC optimize(3)
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define int long long

int preCal[20];
int m10[20];

int checkNumber(int n) {
  string s = to_string(n);
  int type = 0;
  for (auto &i : s) {
    type ^= 1;
    if (type) {
      if (i == '0' || i == '2' || i == '4' || i == '6' || i == '8') {
        return 0;
      }
    } else {
      if (i == '1' || i == '3' || i == '5' || i == '7' || i == '9') {
        return 0;
      }
    }
  }
  return 1;
}

int checkAnswer(int n) {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += checkNumber(i);
  }
  return ans;
}

int getAnswer(int n) {
  int answer = 0;
  int pre = 0;
  int dig = 0;
  for (int i = 1;; i++) {
    if (n / m10[i] == 0) {
      dig = i;
      break;
    }
  }
  int type = 0;
  for (int i = dig; i >= 1; i--) {
    type ^= 1;
    int tmp = n % m10[i] / m10[i - 1];
    int tmp10 = tmp * m10[i - 1];
    for (int j = type; j < tmp; j += 2) {
      answer += preCal[i - 1];
    }
    if (type == 1 && tmp % 2 == 0) {
      break;
    }
    if (type == 0 && tmp % 2 == 1) {
      break;
    }
  }
  for (int i = dig - 1; i >= 1; i--) {
    answer += preCal[i];
  }
  answer += checkNumber(n);
  return answer;
}

void slove() {
  int l, r;
  cin >> l >> r;
  // cerr << endl;
  // cerr << "---" << endl;
  // cerr << checkAnswer(r) << ' ' << checkAnswer(l - 1) << endl;
  // cerr << getAnswer(r) << ' ' << getAnswer(l - 1) << endl;
  // cerr << "---" << endl;
  cout << getAnswer(r) - getAnswer(l - 1) << endl;
}
signed main() {
  preCal[0] = 1;
  m10[0] = 1;
  for (int i = 1; i < 20; i++) {
    preCal[i] = preCal[i - 1] * 5;
    m10[i] = m10[i - 1] * 10;
  }
  fast;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    slove();
  }
}

/*
3
5 15
120 125
779 783
*/