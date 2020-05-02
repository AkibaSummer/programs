#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    queue<int> que;
    while (n--) {
      string s;
      cin >> s;
      if (s == "PUSH") {
        int k;
        cin >> k;
        que.push(k);
      } else if (s == "TOP") {
        if (que.size() == 0) {
          cout << -1 << endl;
        } else {
          cout << que.front() << endl;
        }
      } else if (s == "POP") {
        if (que.size() == 0) {
          cout << -1 << endl;
        } else {
          que.pop();
        }
      } else if (s == "SIZE") {
        cout << que.size() << endl;
      } else {
        que = queue<int>();
      }
    }
  }
}