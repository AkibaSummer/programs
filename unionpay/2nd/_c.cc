#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const long long mod = 998244353;
const long long maxn = 1e6 + 5;
long long jc[maxn];
long long inv[maxn];
long long n, k;

typedef const long long &ct;
inline long long ksm(long long base, ct p)
{
    long long ret = 1;
    for (long long t = p; t; t >>= 1, base = 1ll * base * base % mod)
        if (t & 1)
            ret = 1ll * ret * base % mod;
    return ret;
}

long long C(long long n, long long m)
{
    if (n < m)
        return 0;
    return 1ll * jc[n] * inv[m] % mod * inv[n - m] % mod;
}

long long S(ct n, ct m)
{
    long long ret = 0;
    for (long long t = 0; t <= m; ++t)
        if (t & 1)
            ret = (0ll + ret - 1ll * ksm(m - t, n) * C(m, t) % mod + mod) % mod;
        else
            ret = (0ll + ret + 1ll * ksm(m - t, n) * C(m, t) % mod + mod) % mod;
    return 1ll * ret * inv[m] % mod;
}

int main()
{
    jc[0] = 1;
    inv[0] = 1;
    for (long long t = 1; t < maxn; ++t)
        jc[t] = 1ll * jc[t - 1] * t % mod, inv[t] = 1ll * inv[t - 1] * ksm(t, mod - 2LL) % mod;
    cin >> n;
    long long ans = 0;
    for (long long m = 2; m <= n - 1; m++)
    {
        ans += (1ll * jc[n - m] * C(n, m) % mod * S(n - 2, n - m) % mod) * m % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}