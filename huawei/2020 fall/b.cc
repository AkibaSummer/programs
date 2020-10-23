#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int first = 1;
  for (int i = 2; i <= sqrt(n); i++) {
    while (n % i == 0) {
      n = n / i;
      if (first) {
        cout << i;
        first = 0;
      } else {
        cout << "*" << i;
      }
    }
  }
  if (n != 1) {
    cout << "*" << n;
  }
  cout<<endl;
}