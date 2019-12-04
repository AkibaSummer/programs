#include <bits/stdc++.h>
using namespace std;
enum { L, R };
pair<int, int> max_seg(vector<int> &input, int l, int r, int target = L) {
  if (l == r)
    return {max(0, input[l]), max(0, input[l])};
  else {
    pair<int, int> ret = {0, 0};
    if (target == L) {
      int sum = 0;
      for (int i = l; i <= r; i++) {
        sum += input[i];
        ret.second = max(ret.second, sum);
      }
    } else {
      int sum = 0;
      for (int i = r; i >= l; i--) {
        sum += input[i];
        ret.second = max(ret.second, sum);
      }
    }
    int mid = (l + r) >> 1;
    auto lans = max_seg(input, l, mid, R);
    auto rans = max_seg(input, mid + 1, r, L);
    ret.first = max(ret.first, lans.first);
    ret.first = max(ret.first, rans.first);
    ret.first = max(ret.first, lans.second + rans.second);
    ret.first = max(ret.first, ret.second);
    return ret;
  }
}
int main() {
  int n;
  cin >> n;
  vector<int> input(n);
  for (auto &i : input) cin >> i;
  cout << max_seg(input, 0, n - 1).first << endl;
}
/*
10 
1 -2 -3 4 5 -6 7 -8 9 10
*/