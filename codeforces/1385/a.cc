#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> input(3);
    for (auto &i:input)cin>>i;
    sort(input.begin(), input.end());
    if (input[1] == input[2]) {
      cout << "YES" << endl;
      cout << input[2] << ' ' << input[0] << ' ' << input[0] << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}