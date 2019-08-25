#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e8 + 5;

int pow_mod(int a, int n, int mod) {
    int ret = 1;
    int temp = a % mod;
    while (n) {
        if (n & 1)
            ret = (long long)ret * temp % mod;
        temp = (long long)temp * temp % mod;
        n >>= 1;
    }
    return ret;
}
bool millerRabbin(int n) {
    if (n < 3)
        return n == 2;
    int a = n - 1, b = 0;
    while (a % 2 == 0)
        a /= 2, ++b;
    // test_time 为测试次数,建议设为不小于 8
    // 的整数以保证正确率,但也不宜过大,否则会影响效率
    for (int i = 1, j; i <= 8; ++i) {
        int x = rand() % (n - 2) + 2, v = pow_mod(x, a, n);
        if (v == 1 || v == n - 1)
            continue;
        for (j = 0; j < b; ++j) {
            v = (long long)v * v % n;
            if (v == n - 1)
                break;
        }
        if (j >= b)
            return 0;
    }
    return 1;
}

int isY(int n) {
    if (n <= 5)
        return 1;
    if (n == 8)
        return 1;
    int num2 = 0;
    while (!(n & 1)) {
        n >>= 1;
        num2++;
    }
    if (num2 == 1)
        return 1;
    if (num2 > 2)
        return 0;
    if (millerRabbin(n))
        return 1;
    else
        return 0;
}

int main() {
    // cout<<MAXN;
    int tt;
    scanf("%d", &tt);
    srand(time(NULL)); /* *************** */
    for (int ii = 1; ii <= tt; ii++) {
        int l, r;
        scanf("%d%d", &l, &r);
        int ans = 0;
        for (int i = l; i <= r; i++)
            ans += isY(i);
        printf("Case #%d: %d\n", ii, ans);
    }
}