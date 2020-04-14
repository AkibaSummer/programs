/*
输入一个数学表达式（不要求合法），
求匹配括号对数，落单的左括号与右括号数量

Solution: 顺序走一遍直接匹配就好
*/
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