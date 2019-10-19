#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
  int n;
  cin>>n;
  vector<int> input(n);
  int num1 = 0, num2 = 0;
  for (auto &i : input) {
    cin >> i;
    if (i % 2 && i > 0)
      num1++;
    else if (i % 2 && i < 0)
      num2++;
  }
  int ans1 = min(num1, num2), ans2 = min(num1, num2);
  int flag = 1;
  for (auto &i : input) {
    if (i % 2 == 0)
      cout << i / 2 << endl;
    else if (i > 0) {
      if (ans1) {
        cout << i / 2 << endl;
        ans1--;
      } else {
        if (flag) {
          cout << i / 2 << endl;
          flag = 1 - flag;
        } else {
          cout << (i + 1) / 2 << endl;
          flag = 1 - flag;
        }
      }
    } else {
      if (ans2) {
        cout << i / 2 << endl;
        ans2--;
      } else {
        if (flag) {
          cout << i / 2 << endl;
          flag = 1 - flag;
        } else {
          cout << (i - 1) / 2 << endl;
          flag = 1 - flag;
        }
      }
    }
  }
}
