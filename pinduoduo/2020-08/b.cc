#pragma GCC optimize(3)
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

struct touzi {
  int top, down, left, right, front, back;
  bool operator<(const touzi t) const {
    return top == t.top
               ? (down == t.down
                      ? (left == t.left
                             ? (right == t.right
                                    ? (front == t.front ? (back < t.back)
                                                        : front < t.front)
                                    : right < t.right)
                             : left < t.left)
                      : down < t.down)
               : top < t.top;
  }
};

touzi conv1(touzi t) {
  return {t.front, t.back, t.left, t.right, t.down, t.top};
}
touzi conv2(touzi t) {
  return {t.top, t.down, t.back, t.front, t.left, t.right};
}

touzi convert(touzi t) {
  set<touzi> s;
  s.insert(t);
  queue<touzi> que;
  que.push(t);
  while (!que.empty()) {
    auto now = que.front();
    que.pop();
    if (s.count(conv1(now)) == 0) {
      que.push(conv1(now));
      s.insert(conv1(now));
    }
    if (s.count(conv2(now)) == 0) {
      que.push(conv2(now));
      s.insert(conv2(now));
    }
  }
  for (auto &i : s) {
    return i;
  }
}

signed main() {
  map<touzi, int> cnt;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    touzi t;
    cin >> t.top >> t.down >> t.left >> t.right >> t.front >> t.back;
    cnt[convert(t)]++;
  }
  vector<int> output;
  for (auto &i : cnt) {
    output.push_back(i.second);
  }
  sort(output.begin(), output.end());
  cout << output.size() << endl;
  for (int i = output.size() - 1; i >= 0; i--) {
    cout << output[i] << ' ';
  }
}