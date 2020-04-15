#include <iostream>
#include <map>
using namespace std;
int main() {
  string s;
  cin >> s;
  string now;
  map<string, int> maps;
  // if (cin >> s) {
  //   cout << "error.0001" << endl;
  //   return 0;
  // }
  for (auto &i : s) {
    //    cout << i;
    int flag = 0;
    if (i == ',') {
      maps[now]++;
      now = "";
    } else if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')) {
      if (now == "" && (i >= 'a' && i <= 'z')) {
        cout << "error.0001" << endl;
        return 0;
      } else if (now != "" && (i >= 'A' && i <= 'Z')) {
        cout << "error.0001" << endl;
        return 0;
      }
      now = now + i;
    } else {
      cout << "error.0001" << endl;
      return 0;
    }
  }
  if (now != "") maps[now]++;
  int max = -1;
  string ans;
  for (auto &i : maps) {
    //    cout << i.first << ' ' << i.second << endl;
    if (max < i.second) {
      max = i.second;
      ans = i.first;
    } else if (max == i.second) {
      if (ans > i.first) {
        ans = i.first;
      }
    }
  }
  if (ans == "") {
    cout << "error.0001" << endl;
  } else {
    cout << ans << endl;
  }
}
// Tom,Lily,Tom,Lucy,Lucy,Jack
// Tom,Lily,Tom,Lucy,Lucy,Jack