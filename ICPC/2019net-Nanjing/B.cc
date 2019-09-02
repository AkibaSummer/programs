#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
int qp(int a, int b, int m) {
  int ret = 1;
  while (b) {
    if (b & 1) {
      ret = 1ll * ret * a % m;
    }
    a = 1ll * a * a % m;
    b >>= 1;
  }
  return ret;
}

int phi[1000500], isprime[1000500], prime[300050], sp;
pair<int, int> save[1000500];
void init_phi(int n) {
  memset(isprime, 0, sizeof(isprime));
  sp = 0;
  for (int i = 2; i <= n; i++) {
    if (!isprime[i]) {
      prime[++sp] = i;
      isprime[i] = i;
      phi[i] = i - 1; // if is prime
    }
    for (int j = 1; j <= sp && i * prime[j] <= n; j++) {
      isprime[i * prime[j]] = prime[j];
      if (prime[j] >= isprime[i]) {
        phi[i * prime[j]] =
            phi[i] * prime[j]; // if is not coprime but pi(prime)>1
        break;
      }
      phi[i * prime[j]] = phi[i] * (prime[j] - 1); // if is coprim
    }
  }
}

int slove1(int a, int b, int m, int T) {
  a %= m;
  if (!b) {
    return 1;
  }
  if (a == 0) {
    return 0;
  }
  if (a == 1) {
    return 1;
  }
  int ret = 1;
  int flag = 1;
  for (int i = 1; i < b; i++) {
    ret = qp(a, ret % phi[m], phi[m]);
    // printf("%lld\n",ret);
    if (flag && save[ret].first == T) {
      int sub = i - save[ret].second;
      // printf("%d", (b - 1 - i) / sub * sub);
      // puts("YES");
      i += (b - 1 - i) / sub * sub;
      flag = 0;
    } else
      save[ret] = {T, i};
  }
  // printf("%lld\n", qp(a, ret, m));
  return qp(a, ret, m);
}

int solve(int a, int b,int m) {
  if(m==1){
    return 0;
  }
  if(b==0){
    return 1;
  }
  int ret = solve(a, b-1, phi[m]);
  if (ret==0)ret=phi[m];
  return qp(a,ret,m);
}

int slove2(int a, int b, int m, int T) {
  // int a, b, m;
  // scanf("%d%d%d", &a, &b, &m);
  a %= m;
  if (!b) {
    // puts("1");
    // continue;
    return 1;
  }
  if (a == 0) {
    // puts("0");
    // continue;
    return 0;
  }
  int ret = 1;
  // printf("%d %d\n", phi[m], m);
  int tmp=phi[m];
  for (int i=1;i<b;i++){
  // while (--b) {
    ret = qp(a, ret % tmp, phi[m]);
    
    // printf("%lld\n",ret);
  }
  // printf("%d\n", qp(a, ret, m));
  return qp(a, ret, m);
}
signed main() {
  init_phi(1000002);
  // cout<<phi[10]<<endl;
  int T;
  // printf("%d", 5 * 5 * 5 * 5 * 5 % 233);
  scanf("%lld", &T);
  T++;
  while (--T) {
    int a, b, m;
    scanf("%lld%lld%lld", &a, &b, &m);
    printf("%lld\n", solve(a, b, m));
    // if (slove1(a, b, m, T) != slove2(a, b, m, T)) {
    //   cout << a << ' ' << b << ' ' << m << endl;
    // }
    // else {

    //   cout << a << ' ' << b << ' ' << m <<"YES" <<endl;
    // }
  }
}