#pragma GCC optimize(3)
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"
#define int long long
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
// class linetree {
//   vector<int> tree;
//   void build_in(int node, int l, int r, vector<int> &input) {
//     if (l == r) {
//       tree[node] = input[l];
//     } else {
//       int mid = (l + r) >> 1;
//       build_in(node << 1, l, mid, input);
//       build_in(node << 1 | 1, mid + 1, r, input);
//       tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
//     }
//   }
//   void build(int size, vector<int> &input) {
//     tree = vector<int>(input.size() * 2 + 10);
//     build_in(0, 0, input.size() - 1, input);
//   }
//   int query(int l, int r, int node = 0) {
//     if (l == r) return tree[r];
//     else{
//       int maxx =0 ;

//     }
//   }
// };
void slove() {
  int n, q;
  cin >> n >> q;
  vector<int> input(n);
  for (int i = 1; i < n; i++) cin >> input[i];
  while (q--) {
    int s, k;
    cin >> s >> k;
    int l = s;
    int r = s;
    while (--k) {
      if (l == 1) {
        r = r + 1;
        s = r;
      } else if (r == n) {
        l = l - 1;
        s = l;
      } else if (input[l - 1] < input[r]) {
        l = l - 1;
        s = l;
      } else {
        r = r + 1;
        s = r;
      }
    }
    cout << s << ' ';
  }
  cout << endl;
}
signed main() {
  fast;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    slove();
  }
}