#include <cstdio>

char a[55], b[55], c[55];

// char S[200];
void Main(int t) {
  int n, m;
  scanf("%d%d%s%s%s", &n, &m, a, b, c);
  int shif = b[0] - a[0];
  printf("Case #%d: ", t);
  for (int i = 0; i < m; i++) {
    printf("%c", (c[i] - 'A' - shif + 26) % 26 + 'A');
  }
  puts("");
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    Main(i);
  }
}