#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void slove() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> input(n + 2, vector<int>(m + 2, 1));
    // cout<<input.size()<<' '<<input[0].size();
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        if (input[x][y]) {
            ans++;
            input[x][y] = 0;
            queue<pair<int, int>> que;
            que.push({x, y});
            while (!que.empty()) {
                // puts("233");
                int xx = que.front().first;
                int yy = que.front().second;
                // cout<<xx<<' '<<yy<<endl;
                que.pop();
                if (yy != m && input[xx][yy + 1] &&
                    input[xx - 1][yy + 1] + input[xx + 1][yy + 1] <= 1 &&
                    input[xx][yy + 1 + 1] + input[xx][yy + 1 - 1] <= 1) {
                    input[xx][yy + 1] = 0;
                    que.push({xx, yy + 1});
                    ans++;
                }
                if (yy != 1 && input[xx][yy - 1] &&
                    input[xx - 1][yy - 1] + input[xx + 1][yy - 1] <= 1 &&
                    input[xx][yy - 1 + 1] + input[xx][yy - 1 - 1] <= 1) {
                    input[xx][yy - 1] = 0;
                    que.push({xx, yy - 1});
                    ans++;
                }
                if (xx != 1 && input[xx - 1][yy] &&
                    input[xx - 1 - 1][yy] + input[xx - 1 + 1][yy] <= 1 &&
                    input[xx - 1][yy + 1] + input[xx - 1][yy - 1] <= 1) {
                    input[xx - 1][yy] = 0;
                    que.push({xx - 1, yy});
                    ans++;
                }
                if (xx != n && input[xx + 1][yy] &&
                    input[xx + 1 - 1][yy] + input[xx + 1 + 1][yy] <= 1 &&
                    input[xx + 1][yy + 1] + input[xx + 1][yy - 1] <= 1) {
                    input[xx + 1][yy] = 0;
                    que.push({xx + 1, yy});
                    ans++;
                }
            }
            cout << ans << endl;
        } else {
            cout << 0 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        slove();
    }
}