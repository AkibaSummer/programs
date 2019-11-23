#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast                                                                   \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

long long n, m;
long long findans(int k, vector<int> &num,long long nowans,long long nowsum) {
    if (k == 0) {
        if (nowsum+num[0]<=m){
            return nowans|1;
        }
        else if (nowsum+(n-num[0])<=m){
            return nowans;
        }
        else return -1;
    }
    else {
        if (nowsum+num[k]*(1ll<<k)<=m){
            long long tmp = findans(k-1,num,nowans|(1ll<<k),nowsum+num[k]*(1ll<<k));
            if (tmp!=-1)return tmp;
        }
        if (nowsum+(n-num[k])*(1ll<<k)<=m){
            long long tmp = findans(k-1,num,nowans,nowsum+(n-num[k])*(1ll<<k));
            if (tmp!=-1)return tmp;
        }
        return -1;
    }
}

void slove() {
    cin >> n >> m;
    vector<long long> input(n);
    for (auto &i : input) {
        cin >> i;
    }
    vector<int> num(50,n);
    for (int i = 0; i < 50; i++) {
        for (auto &j : input) {
            if (j & (1ll << i))
                num[i]--;
        }
    }
    cout << findans(49, num, 0,0) << endl;
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
/*
1
 3 1000000000000000
 1000000000000000
 999999999999999
 999999999999998
 */