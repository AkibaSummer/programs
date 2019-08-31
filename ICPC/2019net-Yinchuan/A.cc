#include <algorithm>
#include <cstdio>
using namespace std;

int n, p, q, m;
unsigned int SA, SB, SC;
unsigned int rng61() {
  SA ^= SA << 16;
  SA ^= SA >> 5;
  SA ^= SA << 1;
  unsigned int t = SA;
  SA = SB;
  SB = SC;
  SC ^= t ^ SA;
  return SC;
}

int s[5000050], top = 0;
void PUSH(int t) { s[++top] = max(t, s[top - 1]); }

void POP() {
  if (top)
    top--;
}

void Main(int t) {
  scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
  top = 0;
  s[0] = 0;
  printf("Case #%d: ", t);
  long long ret = 0;
  for (int i = 1; i <= n; i++) {
    if (rng61() % (p + q) < p)
      PUSH(rng61() % m + 1);
    else
      POP();
    ret = ret ^ (1ll * i * s[top]);
  }
  printf("%lld\n", ret);
}
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    Main(i);
  }
}