#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast                                                                   \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)
#define int long long
long long n, h;
void fillsuma(int pos, int nowpos, long long nowsum, vector<long long> &inputb,
              vector<long long> &sumb) {
    if (pos < 0)
        return;
    if (nowsum >= h) {
        sumb[nowpos] = 1;
        // sumb[nowpos] = nowsum;
    }
    if (nowsum + inputb[pos] >= h) {
        sumb[nowpos | (1 << pos)] = 1;
        // sumb[nowpos | (1 << pos)] = nowsum + inputb[pos];
    }
    fillsuma(pos - 1, nowpos, nowsum, inputb, sumb);
    fillsuma(pos - 1, nowpos | (1 << pos), nowsum + inputb[pos], inputb, sumb);
}

void slove() {
    cin >> n >> h;
    vector<long long> inputa(n), inputb(n), suma(1 << n), sumb(1 << n),
            totb(1 << n);
    for (auto &i : inputa) {
        cin >> i;
    }
    for (auto &i : inputb) {
        cin >> i;
    }
    fillsuma(n - 1, 0, 0, inputb, sumb);
    fillsuma(n - 1, 0, 0, inputa, suma);
    totb[0] = sumb[(1 << n) - 1];
    for (int i = 0; i < n; i++) {
        totb[1ll << i] = sumb[((1 << n) - 1) - (1ll << i)] + totb[0];
    }
    long long ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        if (i - (i & (-i))) {
            int tmp1 = i & (-i);
            int tmp = i - (i & (-i));
            int tmp2 = tmp & (-tmp);
            totb[i] = totb[i - tmp1] + totb[i - tmp2] - totb[i - tmp1 - tmp2];
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        if (suma[i]) {
            ans += totb[i];
        }
    }
    cout << ans << endl;
}
signed main() {
    fast;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        slove();
    }
}