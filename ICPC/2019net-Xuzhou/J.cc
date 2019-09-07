#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct edge {
  int nx, to;
} e[2000050];

int head[1000050], mal = 1;
int deg[1000050];

void addedge(int u, int v) {
  e[mal].to = v;
  e[mal].nx = head[u];
  head[u] = mal++;
}

int mxdep[1000050], dep[1000050];

void dfs1(int u, int f) {
  dep[u] = dep[f] + 1;
  mxdep[u] = dep[u];
  for (int i = head[u]; i; i = e[i].nx) {
    int v = e[i].to;
    if (v == f) {
      continue;
    }
    deg[u]++;
    dfs1(v, u);
    mxdep[u] = max(mxdep[u], mxdep[v]);
  }
}

const long long mod = 1000000007;

long long qp(long long a, long long b) {

  long long ret = 1;
  while (b) {
    if (b & 1)
      ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}

long long fac[1000050], invf[1000050], inv[1000050];
void initinv(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
  invf[0] = 1;
  invf[n] = qp(fac[n], mod - 2);
  for (int i = n - 1; i >= 1; i--) {
    invf[i] = invf[i + 1] * (i + 1) % mod;
  }

  inv[0] = 1;
  for (int i = n - 1; i >= 1; i--) {
    inv[i] = invf[i] * fac[i - 1] % mod;
    // invf[i] = invf[i+1] * (i+1) % mod;
  }
}

// long long prob[1000050];
long long dfs2(int u, int f) {
  // if(head[u] == 0) {
  //     ret+=prob[u];
  //     return ;
  // }
  if (deg[u] == 0) {
    // printf("orz %d", u);
    return (mxdep[u] != mxdep[1]);
  }
  long long ret = 0;

  for (int i = head[u]; i; i = e[i].nx) {
    int v = e[i].to;
    if (v == f) {
      continue;
    }
    // long long tt;
    // printf("...%d %d %lld\n",u,v, tt = );
    // prob[v] = prob[u] * (1 - qp((deg[u]-1) * invf[deg[u]], deg[u]) + mod) %
    // mod;
    ret += dfs2(v, u);
  }

  if (deg[u] == 1) {
    return ret;
  }
  return qp((inv[deg[u]] * ret) % mod, deg[u]);
  // return (((1-qp(inv[deg[u]], deg[u])+mod)%mod) * (deg[u]-1)%mod) * ret %
  // mod;
}

int main() {
  int n;
  scanf("%d", &n);
  initinv(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  dep[0] = 0;
  dfs1(1, 0);

  // for(int i=1;i<=n;i++) {
  //     printf("%d %d %d %d...\n",i,dep[i],mxdep[i], deg[i]);
  // }
  // printf("%lld\n", dfs2(1,0) * 4 % mod);
  printf("%lld\n", (1 - dfs2(1, 0) + mod) % mod);
}
