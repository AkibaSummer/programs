#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

int query(int pos) {
  cout << pos << endl;
  int ret;
  cin >> ret;
  return ret;
}

void setmem(vector<int> &mem, int b, int type) {
  switch (type) {
    case 1:
      for (int i = 1; i <= b; i++) {
        mem[i] = 1 - mem[i];
      }
      break;
    case 2:
      for (int i = 1; i <= b / 2; i++) {
        swap(mem[i], mem[b + 1 - i]);
      }
      break;
    default:
      break;
  }
}

int main() {
  int t, b;
  cin >> t >> b;
  for (int tt = 1; tt <= t; tt++) {
    vector<int> mem(b + 2);

    int type1 = -1, info1 = 0;
    int type2 = -1, info2 = 0;

    int now = 1;
    while (1) {
      int flag1 = -1, flag2 = -1;
      if (type1 != -1) {
        flag1 = (query(type1) == info1);  // flag1==1 -> without bitreverse
        if (flag1 == 0) {
          setmem(mem, b, 1);
        }
      }
      if (type2 != -1) {
        flag2 = (query(type2) == info2);
        if (flag2 == 0 && flag1 == 1) {
          setmem(mem, b, 2);
        } else if (flag2 == 1 && flag1 == 0) {
          setmem(mem, b, 2);
        } else if (flag1 == -1 && flag2 == 0) {
          setmem(mem, b, 2);
        }
      }

      if (now > b / 2) {
        break;
      }

      int waste = (type1 == -1) + (type2 == -1);
      while (waste--) {
        query(1);
      }

      for (int i = now; i < now + 4; i++) {
        mem[i] = query(i);
        mem[b + 1 - i] = query(b + 1 - i);
      }
      if (type1 != -1) {
        info1 = mem[type1];
      }
      if (type2 != -1) {
        info2 = mem[type2];
      }
      for (int i = now; i < now + 4; i++) {
        if (type1 == -1 && mem[i] == mem[b + 1 - i]) {
          type1 = i;
          info1 = mem[i];
        } else if (type2 == -1 && mem[i] != mem[b + 1 - i]) {
          type2 = i;
          info2 = mem[i];
        }
      }
      now += 4;
    }
    for (int i = 1; i <= b; i++) {
      cout << mem[i];
    }
    cout << endl;
    string ans;
    cin >> ans;
    if (ans == "N") {
      break;
    }
  }
}
/*
1010101010
0101010101
*/