#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
// #include <iomanip>
// #include <iostream>
#define endl "\n"
double x[10050];
using namespace std;
double eps = 1e-7;
inline int sig(double x) {
    if (fabs(x) < eps) {
        return 0;
    }
    return x < 0 ? -1 : 1;
}

bool cmp(double x, double y) { return sig(x - y) > 0; }

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int T;
    // cin >> T;
    scanf("%d",&T);
    // cout.precision(15);
    // cout << fixed;
    while (T--) {
        int n;
        // cin >> n;
        // memset(sel,0,sizeof(sel[0]) * (n+1));
        double ret = 0;
        // int retid;
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            // cin >> x[i];
            scanf("%lf",x+i);
            if (ret < x[i]) {
                ret = x[i];
            }
        }
        if (sig(ret - 0.5) >= 0) {
            // cout << fixed << ret << endl;
            printf("%.8lf\n",ret);
        } else {
            sort(x + 1, x + 1 + n, cmp);
            double s0 = 1 - x[1], s1 = x[1];
            // cout << s0 << " " << s1 << endl;
            for (int i = 2; i <= n; i++) {
                if (sig(s1 - s0) >= 0) {
                    break;
                }
                s1 = s1 * (1 - x[i]) + s0 * x[i];
                s0 = s0 * (1 - x[i]);
                // cout << s0 << " " << s1 << endl;
            }
            // cout << fixed << s1 << endl;
            printf("%.8lf\n",s1);
        }
    }
}

/*
4
3
0.2 0.3 0.4
3
0.3 0.2 0.4
3
0.4 0.3 0.2

 */