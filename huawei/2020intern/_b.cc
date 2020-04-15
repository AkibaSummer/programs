#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int hasresult = 0;

// set<char> sets;

string x1,x2,x3;
int ans1, ans2, ans3;
int flag = -1;
map<char, int> maps;
pair<int, int> getresult(string s) {
  //cerr<<s<<endl;
  int ret = 0;
  for (auto &i : s) {
    if (!maps.count(i)) {
      return {0, -1};
    } else {
      ret = (ret << 4) + maps[i];
    }
  }
  //cerr << ret << endl;
  return {1, ret};
}

int judge3(string &b) {
  if (!(b[0] == '0' && (b[1] == 'x' || b[1] == 'X'))) {
    return -1;
  }
  x3=b.substr(0,2);
  b = b.substr(2);
  int nextc = b.find(']');
  if (nextc == -1) {
    return -1;
  } else {
    auto ret = getresult(b.substr(0, nextc));
    if (ret.first) {
      ans3 = ret.second;
      b = b.substr(nextc + 1);
      return 1;
    } else
      return -1;
  }
}
int judge2(string &b) {
  if (!(b[0] == '0' && (b[1] == 'x' || b[1] == 'X'))) {
    return -1;
  }
  x2=b.substr(0,2);
  b = b.substr(2);
  int nextc = b.find(',');
  if (nextc == -1) {
    return -1;
  } else {
    auto ret = getresult(b.substr(0, nextc));
    if (ret.first) {
      ans2 = ret.second;
      b = b.substr(nextc + 1);
      if (b.find("val=") != 0) {
        return -1;
      } else {
        b = b.substr(b.find("val=") + 4);
        return judge3(b);
      }
    } else
      return -1;
  }
}
int judge1(string &b) {
  if (!(b[0] == '0' && (b[1] == 'x' || b[1] == 'X'))) {
    return -1;
  }
  //cerr << b << endl;
  x1=b.substr(0,2);
  b = b.substr(2);
  int nextc = b.find(',');
  if (nextc == -1) {
    return -1;
  } else {
    auto ret = getresult(b.substr(0, nextc));
    if (ret.first) {
      ans1 = ret.second;
      b = b.substr(nextc + 1);
      if (b.find("mask=") != 0) {
        return -1;
      } else {
        b = b.substr(b.find("mask=") + 5);
        return judge2(b);
      }
    } else
      return -1;
  }
}

int main() {
  string sets_C = "0123456789abcdefABCDEF";
  int sets_I[] = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                  11, 12, 13, 14, 15, 10, 11, 12, 13, 14, 15};
  for (int i = 0; i < 22; i++) maps[sets_C[i]] = sets_I[i];
  string a, b;
  cin >> a >> b;
  a = a + "[addr=";
  int pos = 0;
  int has=0;
  while ((pos = b.find(a)) != -1) {
    if (pos != 0 && b[pos - 1] != ',') {
      b = b.substr(pos + a.size());
      continue;
    }
    b = b.substr(pos + a.size());
    if (judge1(b) == 1) {
      cout<<hex<<x1<<ans1<<' '<<x2<<ans2<<' '<<x3<<ans3<<endl;
      has=1;
      // printf("0x%x 0x%x 0x%x\n", ans1, ans2, ans3);
      // cout<<ans1<<' '<<ans2<<' '<<ans3<<endl;
    };
  }
  if (has==0){
    cout<<"FAIL"<<endl;
  }
}