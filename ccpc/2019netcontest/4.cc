#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void slove() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> links(n);
    map<pair<long long, int>, int> maps;
    int minw = 1e9 + 5;
    int numm = 0;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        links[u - 1].push_back({v - 1, w});
        maps[{w, v - 1}]++;
        numm++;
        minw = min(minw, w);
    }
    vector<int> query(q);
    int maxquery = 0;
    for (auto &i : query) {
        cin >> i;
        maxquery = max(maxquery, i);
    }
    vector<long long> ans(maxquery);
    int nowans = 0;
    long long maxxans = 1ll << 60;

    for (int i = 0; i < maxquery; i++) {
        auto l = maps.begin();
        for (int j = 1; j <= l->second && i < maxquery; j++, i++) {
            ans[i] = l->first.first;
        }
        i--;
        if (i == maxquery)
            break;
        for (auto &i : links[l->first.second]) {
            if (i.second + l->first.first <= maxxans) {
                numm += l->second;
                maps[{i.second + l->first.first, i.first}] += l->second;
            }
        }
        while (numm >= maxquery) {
            auto r = maps.end();
            r--;
            if (numm - r->second < maxquery)
                break;
            maxxans = r->first.first;
            numm -= r->second;
            maps.erase(r);
        }
        maps.erase(l);
    }
    for (auto &i : query) {
        cout << ans[i - 1] << endl;
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