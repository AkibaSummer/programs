#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
// #define int long long
struct input {
    int t, x, y;
};

int k[1000][1000];
int p[500005];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    vector<input> inputs(q);
    for (auto &i : inputs) {
        cin >> i.t >> i.x >> i.y;
        if (i.t == 1) {
            for (int j = 1; j <= 700; j++) {
                k[j][i.x % j] += i.y;
            }
            p[i.x]+=i.y;

        } else {
            if (i.x <= 700) {
                cout << k[i.x][i.y] << endl;
            } else {
                int ans = 0;
                for (int j = i.y; j <= 500000; j += i.x) {
                    ans += p[j];
                }
                cout << ans << endl;
            }
        }
    }
}