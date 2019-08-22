#include <bits/stdc++.h>
using namespace std;
#define int long long

int get4(int n, int x=4) {
    int cnt = 0, k;
    for (int i = 1;k = n / i;i *= 10) {
        cnt += (k / 10) * i;
        int cur = k % 10;
        if (cur > x) {
            cnt += i;
        } else if (cur == x) {
            cnt += n - k * i + 1;
        }
    }
    return cnt;
}

void add(int now,vector<pair<pair<int,int>,int>>&vec){
    vector<pair<int,int>> ret;
    for (auto &i:vec){
        ret.push_back({i.first.first,i.second});
        ret.push_back({i.first.second+1,-i.second});
        ret.push_back({i.first.first+now,i.second});
        ret.push_back({i.first.second+1+now,-i.second});
    }
    sort(ret.begin(),ret.end());
    vec.clear();
    int l=ret[0].first,w=ret[0].second;
    for (int i=1;i<ret.size();i++){
        if (ret[i].first==l)w+=ret[i].second;
        else {
            vec.push_back({{l,ret[i].second-1},w});
            l=ret[i].first;
            w+=ret[i].second;
        }
    }
    
}

void out(vector<pair<pair<int,int>,int>> &now){
    for(auto &i:now)cout<<i.first.first<<' '<<i.first.second<<' '<<i.second<<endl;
    cout<<endl;
}

void slove(){
    int n;
    cin>>n;
    vector<int> input(n);
    vector<pair<pair<int,int>,int>> now;
    for (auto &i:input) cin>>i;
    now.push_back({{input[0],input[0]},1});
    for (int i=1;i<n;i++){
        add(input[i],now);
        out(now);
    }
    long long ans=0;
    for (auto &i:now){
        ans+=(get4(i.first.second)-get4(i.first.first-1))*i.second;
    }
    cout<<ans<<endl;
}

signed main(){
    int tt;
    cin>>tt;
    while(tt--){
        slove();
    }
}