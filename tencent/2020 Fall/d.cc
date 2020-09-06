#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> input(n), input1;
  for (auto &i : input) {
    cin >> i;
  }
  input1 = input;
  sort(input.begin(), input.end());
  int l = input[n / 2 - 1], r = input[n / 2];
  for (auto &i : input1) {
    if (i <= l) {
      cout << r << endl;
    } else {
      cout << l << endl;
    }
  }
}