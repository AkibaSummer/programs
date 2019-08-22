#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

#define int long long

void slove(){
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    long long ans=0;
    ans+=s.size()*a+2*b;
    vector<pair<int,int>> tmp,tmp2;
    int pre='0',size=0;
    for (int i=0;i<n;i++){
        if (s[i]==pre)size++;
        else {
            tmp.push_back({pre,size});
            pre=s[i];
            size=1;
        }
    }
    tmp.push_back({pre,size});
    for (int i=1;i<tmp.size()-1;i++){
        if (tmp[i].first=='0'){
            if ((tmp[i].second-1)*b+2*a<=(tmp[i].second-1)*(b*2)){
                tmp[i].first='0';
            }
            else {
                tmp[i].first='1';
            }
        }
    }
    tmp2.push_back({'0',0});
    for (auto &i:tmp){
        if (i.first==tmp2.back().first)
            tmp2.back().second+=i.second;
            else tmp2.push_back(i);
    }
    for (auto &i:tmp2){
        cerr<<i.first<<' '<<i.second<<endl;
        if (i.first=='0'){
            ans+=(i.second-1)*b;
        }
        else ans+=(i.second+1)*(b*2)+2*a;
    }
    cout<<ans<<endl;
}

signed main(){
    int t;
    cin>>t;
    // t=1;
    while(t--){
        slove();
    }
}