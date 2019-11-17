#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast                                                                   \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

long long n, h, ans;

void getans1(int n, pair<long long, long long> sum, vector<long long> &a,
             vector<long long> &b) {
    if (n < 0) {
        if (sum.first >= h && sum.second >= h)
            ans++;
    } else {
        getans1(n - 1, {sum.first + a[n], sum.second + b[n]}, a, b);
        getans1(n - 1, {sum.first, sum.second + b[n]}, a, b);
        getans1(n - 1, {sum.first + a[n], sum.second}, a, b);
    }
}

void slove1() {
    vector<long long> a(n), b(n);
    ans = 0;
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    getans1(n - 1, {0, 0}, a, b);
    cout << ans << endl;
}

void fill2(int n, pair<long long, long long> sum, vector<long long> &a,
           vector<long long> &b, vector<pair<long long, long long>> &fir) {

    if (n < 0) {
        fir.push_back(sum);
    } else {
        fill2(n - 1, {sum.first + a[n], sum.second + b[n]}, a, b, fir);
        fill2(n - 1, {sum.first, sum.second + b[n]}, a, b, fir);
        fill2(n - 1, {sum.first + a[n], sum.second}, a, b, fir);
    }
}
void fillbeg(int n, pair<long long, long long> sum, vector<long long> &a,
             vector<long long> &b, vector<pair<long long, long long>> &sec) {

    if (n < 10) {
        sec.push_back(sum);
    } else {
        fillbeg(n - 1, {sum.first + a[n], sum.second + b[n]}, a, b, sec);
        fillbeg(n - 1, {sum.first, sum.second + b[n]}, a, b, sec);
        fillbeg(n - 1, {sum.first + a[n], sum.second}, a, b, sec);
    }
}

void slove2() {
    vector<long long> a(n), b(n);
    vector<pair<long long, long long>> fir, sec;
    fir.reserve(1 << 16);
    fill2(9, {0, 0}, a, b, fir);
    sort(fir.begin(), fir.end());
    sec.reserve(1 << 16);
    fillbeg(n - 1, {0, 0}, a, b, sec);
    sort(sec.begin(), sec.end());
    

    for (auto &i:fir){

    }
}
void slove() {
    cin >> n >> h;
    if (n <= 12) {
        slove1();
    } else {
        slove1();
    }
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