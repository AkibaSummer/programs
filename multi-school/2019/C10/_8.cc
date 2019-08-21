#include <bits/stdc++.h>
using namespace std;
inline void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct cmp {
    bool operator()(const pair<int, pair<int, int>> &a,
                    const pair<int, pair<int, int>> &b) {
        if (a.first == b.first) {
            if (a.second.first == b.second.first) {
                return a.second.second < b.second.second;
            } else {
                return a.second.first > b.second.first;
            }
        } else
            return a.first < b.first;
    }
};

void slove() {
    int n;
    cin >> n;
    vector<pair<int, int>> input(n);
    for (auto &i : input)
        cin >> i.first >> i.second;
    priority_queue<pair<pair<int, int>, int>> nowin1, nowdel1;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   cmp>
        nowdel2, nowdelnum, nowin2;
    int nowans = 0;
    for (auto &i : input) {
        nowin1.push({i, 0});
        // in[1].push(i);
        nowin2.push({i.first + i.second, i});
        // in2[1].push({i.first+i.second,i});
    }
    for (int i = 1; i <= 2 * n; i++) {
        //        auto &nowin1 = in;
        // auto &prein=in[1-i%2];
        //        auto &nowin2 = in2;
        // auto &prein2=in2[1-i%2];
        //        auto &nowdel2 = del;
        // auto &predel=del[1-i%2];
        //        auto &nowans = ans;
        while (!nowin1.empty() && !nowdel1.empty() &&
               nowin1.top().first == nowdel1.top().first) {
            nowin1.pop();
            nowdel1.pop();
        }
        if (!nowin1.empty() && !nowdel1.empty()) {
            auto tmp = nowin1.top();
            nowin1.pop();
            while (!nowin1.empty() && !nowdel1.empty() &&
                   nowin1.top().first == nowdel1.top().first) {
                nowin1.pop();
                nowdel1.pop();
            }
            nowin1.push(tmp);
        }
        while (!nowin2.empty() && !nowdel2.empty() &&
               nowin2.top() == nowdel2.top()) {
            nowin2.pop();
            nowdel2.pop();
        }
        while (!nowin2.empty() && !nowdelnum.empty() &&
               nowin2.top().first == nowdelnum.top().first) {
            nowin2.pop();
            nowdelnum.pop();
        }
        if (i == 1) {
            nowans = nowin1.top().first.first;
            nowdel2.push({nowin1.top().first.first + nowin1.top().first.second,
                          nowin1.top().first});
            auto tmp = nowin1.top();
            nowin1.pop();
            nowin1.push({{tmp.first.second, tmp.first.first}, -1});
            cout << nowans << ' ';
        } else if (i % 2 == 1) {
            int ans1 = nowin2.empty() ? -1 : nowin2.top().first + nowans;
            auto tmp1 = nowin1.top();
            nowin1.pop();
            int ans2 = nowin1.top().first.first + tmp1.first.first + nowans;
            if (ans1 >= ans2) {
                nowdel1.push({nowin2.top().second, 0});
                nowin1.push(tmp1);
                nowin2.pop();
                nowans = ans1;
                // if (tmp1.second!=-1)
            } else {
                if (nowin1.top().second == -1) {
                    nowin2.push(
                        {nowin1.top().first.first + nowin1.top().first.second,
                         {nowin1.top().first.second,
                          nowin1.top().first.first}});
                    nowdelnum.push(
                        {nowin1.top().first.first + nowin1.top().first.second,
                         nowin1.top().first});
                    nowin1.pop();
                } else {
                    auto tmp = nowin1.top();
                    nowdel2.push(
                        {tmp.first.first + tmp.first.second, tmp.first});
                    nowin1.pop();
                    nowin1.push({{tmp.first.second, tmp.first.first}, -1});
                }
                if (tmp1.second != -1) {
                    nowdel2.push(
                        {tmp1.first.first + tmp1.first.second, tmp1.first});
                    nowin1.push({{tmp1.first.second, tmp1.first.first}, -1});
                } else {
                    nowin2.push({tmp1.first.first + tmp1.first.second,
                                 {tmp1.first.second, tmp1.first.first}});
                    nowdelnum.push({tmp1.first.first + tmp1.first.second,
                                    {tmp1.first.second, tmp1.first.first}});
                    // nowin1.pop();
                }
                nowans = ans2;
            }
            cout << nowans << ' ';
        } else {
            // cout<<endl<<nowans<<' '<<nowans+nowin1.top().first<<' ';
            cout << nowans + nowin1.top().first.first << " \n"[i == 2 * n];
        }
    }
}

int main() {
    fast();
    int tt;
    cin >> tt;
    while (tt--) {
        slove();
    }
}

/*
1
3
1 3
2 2
3 1
*/