#include <bits/stdc++.h>
using namespace std;
int find_k_num(vector<int> &input, int L, int R, int k) {
  int l = L, r = R, m = (L + R) >> 1;
  int mid = input[l];
  while (l < r) {
    while (l < r && input[r] >= mid) r--;
    if (l < r) input[l++] = input[r];
    while (l < r && input[l] < mid) l++;
    if (l < r) input[r--] = input[l];
  }
  input[l] = mid;
  if (l < k - 1)
    return find_k_num(input, l + 1, R, k);
  else if (l > k - 1)
    return find_k_num(input, L, l - 1, k);
  else
    return input[l];
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> input(n);
  for (auto &i : input) cin >> i;
  cout << find_k_num(input, 0, n - 1, k) << endl;
}
/*
10
1 6 4 2 3 9 10 8 7 5
*/