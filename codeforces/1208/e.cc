#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1 << 30;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, w;
    cin >> n >> w;
    vector<long long> ans(w);
    vector<long long> add(w+1);
    for (int tt = 1; tt <= n; tt++) {
        int l;
        cin >> l;
        vector<int> input(l);
        int maxnum = -inf;
        for (auto &i : input) {
            cin >> i;
            // i=1;
            maxnum = max(maxnum, i);
        }
        if (w >= 2 * l) {
            int nowmax = 0;
            for (int i = 0; i < l - 1; i++) {
                nowmax = max(nowmax, input[i]);
                ans[i] += nowmax;
            }
            nowmax = 0;
            for (int i = l - 1; i > 0; i--) {
                nowmax = max(nowmax, input[i]);
                ans[w - l + i] += nowmax;
            }
            maxnum = max(0ll, maxnum);
            add[l - 1] += maxnum;
            add[w - l + 1] -= maxnum;
        } else {
            int width = w - l + 1;
            priority_queue<int> maxx, del;
            for (int i = 1; i <= width; i++) {
                maxx.push(0);
            }
            int ll = -width-1, rr = -1;
            for (int i = 0; i < w; i++) {
                rr++;
                if (rr<l)maxx.push(input[rr]);
                else maxx.push(0);
                ll++;
                if (ll<0)del.push(0);
                else del.push(input[ll]);
                while(!maxx.empty()&&!del.empty()&&maxx.top()==del.top()){
                    maxx.pop();
                    del.pop();
                }
                ans[i]+=maxx.top();
            }
        }
    }
    long long tmp=0;
    for (int i=0;i<w;i++){
        tmp+=add[i];
        ans[i]+=tmp;
    }
    for (int i=0;i<w;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}