#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
char input[400005];

void slove(int len) {
  int ans = 0, now = 0;
  for (int i = 1; i <= len; i++) {
    if (input[i] == '.')
      continue;
    else if (input[i] == '*') {
      input[i] = '.';
      now++;
      ans = max(ans, now);
    } else {
      if ((input[i - 1] == '.' && now) || (input[i + 1] == '*')) {
        if (input[i + 1] == '#') now--;
        continue;
      } else
        break;
    }
  }
  printf("%d\n", ans);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", input + 1);
    slove(strlen(input + 1));
  }
}
