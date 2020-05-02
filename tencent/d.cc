#include <iostream>
#include <queue>
using namespace std;

// 用两个栈操作的话peek和add操作交替则复杂度为O(n)，感觉复杂度有问题所以就用通常队列来做

int main() {
  int n;
  cin >> n;
  queue<int> que;
  while (n--) {
    string s;
    cin >> s;
    if (s == "add") {
      int n;
      cin >> n;
      que.push(n);
    }
    if (s == "peek") {
      cout << que.front() << endl;
    }
    if (s == "poll") {
      que.pop();
    }
  }
}