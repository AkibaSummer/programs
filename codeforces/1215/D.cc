// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define endl "\n"

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt1 = 0, cnt2 = 0, num1 = 0, num2 = 0;
  for (int i = 0; i < n / 2; i++) {
    if (s[i] == '?')
      cnt1++;
    else
      num1 += s[i] - '0';
  }
  for (int i = n / 2; i < n; i++) {
    if (s[i] == '?')
      cnt2++;
    else
      num2 += s[i] - '0';
  }
  // cout << num1 << ' ' << num2 << ' ' << cnt1 << ' ' << cnt2 << endl;
  if (- num1 + num2 == (cnt1 - cnt2) / 2 * 9)
    cout << "Bicarp" << endl;
  else
    cout << "Monocarp" << endl;
}