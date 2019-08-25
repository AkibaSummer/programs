#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first * b.second > a.second * b.first;
}

void slove() {
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> S(m);
    int tot1 = 0, tot2 = 0;
    for (auto &i : S) {
        cin >> i.first >> i.second;
        tot1 += i.first;
        tot2 += i.second;
    }
    sort(S.begin(), S.end(), cmp);
    vector<int> sum1(m), sum2(m);
    sum1[0] = S[0].first;
    sum2[0] = S[0].first;
    for (int i = 1; i < m; i++) {
        sum1[i] = sum1[i - 1] + S[i].first;
        sum2[i] = sum2[i - 1] + S[i].second;
    }
    for (int i = 1; i <= n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l > tot1) {
            printf("N");
            continue;
        }
        int pos = lower_bound(sum1.begin(), sum1.end(), l) - sum1.begin();
        int sub = S[pos].first-(l - (sum1[pos]-S[pos].first));
        int another = S[pos].second*sub/S[pos].first+(tot2-sum2[pos]);
        if (another>=r)printf("Y");
        else printf("N");
    }
}

int main() {
    int tt;
    cin>>tt;
    for (int ii = 1; ii <= tt; ii++) {
        printf("Case #%d: ", ii);
        slove();
        puts("");
    }
}