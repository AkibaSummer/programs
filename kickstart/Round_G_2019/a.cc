#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast                                                                   \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

void slove() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> isexist(n + 1, 1);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        isexist[k] = 0;
    }
    vector<long long> cnt(n + 1), totnum(n + 1);
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        cnt[k]++;
    }
    for (int i = 1; i <= n; i++) {
        int now = i;
        if (cnt[i]) {
            while (now <= n) {
                totnum[now] += cnt[i];
                now += i;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += isexist[i] * totnum[i];
    }
    cout << ans << endl;
}
int main() {
    fast;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        slove();
    }
}