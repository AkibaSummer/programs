#include <iostream>
using namespace std;
int main() {
  string s;
  cin >> s;
  int a = 0, b = 0, c = 0;
  int l = 0;
  for (auto &i : s) {
    if (i == '(') {
      l++;
    } else if (i == ')') {
      if (l > 0) {
        l--;
        a++;
      } else {
        c++;
      }
    }
  }
  cout << a << ' ' << l << ' ' << c << endl;
}