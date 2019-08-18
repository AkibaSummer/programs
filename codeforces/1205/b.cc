#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1ll<<50;
const int maxn=130;
int val[maxn + 1][maxn + 1]; // 原图的邻接矩阵
inline int floyd(const int &n) {
    static int dis[maxn + 1][maxn + 1]; // 最短路矩阵
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dis[i][j] = val[i][j]; // 初始化最短路矩阵
    int ans = inf;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i < k; ++i)
            for (int j = 1; j < i; ++j)
                ans = min(ans, dis[i][j] + val[i][k] + val[k][j]); // 更新答案
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] =
                    min(dis[i][j],
                        dis[i][k] + dis[k][j]); // 正常的 floyd 更新最短路矩阵
    }
    if (ans >= inf)
        return -1;
    return ans;
}

signed main() {
    int n;
    cin >> n;
    vector<int> input(n);
    vector<vector<int>> cnt(62);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    sort(input.begin(),input.end(),greater<int>());
    input.erase(find(input.begin(),input.end(),0),input.end());
    n=input.size();
    // cout<<n<<endl;
    for (int i=0;i<n;i++){
        for (int j = 0; j < 62; j++) {
            if ((input[i] >> j) & 1) {
                cnt[j].push_back(i + 1);
                if (cnt[j].size()>=3){
                    cout<<3<<endl;
                    return 0;
                }
            }
        }
    }
    // cout<<233<<endl;
    for (auto &i : cnt) {
        if (i.size() >= 3) {
            cout << 3 << endl;
            return 0;
        }
    }
    // vector<vector<int>> val(n+1,vector<int>(n+1),inf);
    for (int i=0;i<=maxn;i++){
        for (int j=0;j<maxn;j++){
            val[i][j]=inf;
        }
    }
    for (auto &i : cnt) {
        if (i.size() == 2) {
            val[i[0]][i[1]] = val[i[1]][i[0]] = 1;
        }
    }
    cout << floyd(n) << endl;
}