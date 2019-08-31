#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct ss {
  int s, id;
} s[205];
vector<int> r;
bool cmp(ss &x, ss &y) { return x.s < y.s; }
int f[205][205][205];
int rnk[205], rrnk[205];
const int INF = 0x3f3f3f3f;
int e[205][205];
void Main(int t) {
  int n, q;
  scanf("%d%d", &n, &q);

  r.clear();
  for (int i = 1; i <= n; i++) {
    scanf("%d", &s[i].s);
    s[i].id = i;
    r.push_back(s[i].s);
  }
  sort(s + 1, s + 1 + n, cmp);
  sort(r.begin(), r.end());
  r.push_back(100050);
  for (int i = 1; i <= n; i++) {
    rnk[s[i].id] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int tt;
      scanf("%d", &tt);
      e[rnk[i]][rnk[j]] = tt;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      f[0][i][j] = (i == j) ? 0 : e[i][j];
      // printf("%d ", f[0][i][j]);
    }
    // puts("");
  }
  // puts("-----");
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        f[k][i][j] = f[k - 1][i][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        f[k][i][j] = min(f[k][i][j], f[k - 1][i][k] + f[k - 1][k][j]);
      }
    }
    // for(int i =1;i<=n;i++) {
    //     for(int j =1;j<=n ;j++) {
    //         printf("%d ", f[k][i][j]);
    //     }
    //     puts("");
    // }
    // puts("-----");
  }

  printf("Case #%d:", t);
  puts("");
  for (int i = 1; i <= q; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    int rr = upper_bound(r.begin(), r.end(), w) - r.begin();
    // printf("%d %d %d ",rr,rnk[u],rnk[v]);
    // int ans=INF;
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++){
    //         ans=min(f[rr][i][j]+e[u][i]+e[v][j],ans);
    //     }
    // }
    printf("%d\n", f[rr][rnk[u]][rnk[v]]);
    // printf("%d\n",ans);
  }
}

int main() {
  int T;
  r.reserve(205);
  scanf("%d", &T);
  // while(T--) {
  for (int i = 1; i <= T; i++) {
    Main(i);
  }
  // }
}