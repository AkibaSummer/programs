#include <bits/stdc++.h>
using namespace std;

void slove(int t){
    int k,n;
    cin>>k>>n;
    vector<pair<long long,long long> > input(n);
    for (auto &i:input)cin>>i.first;
    for (auto &i:input)cin>>i.second;
    sort(input.begin(),input.end());
    long long ans=1ll<<60;
    for (int i=0;i<n;i++){
        long long tempans=input[i].second;
        priority_queue<long long,vector<long long>,greater<long long>> orz;
        for (int j=0;j<i;j++){
            orz.push(input[j].second+input[i].first-input[j].first);
        }
        for (int j=i+1;j<n;j++){
            orz.push(input[j].second+input[j].first-input[i].first);
        }
        for (int j=1;j<=k;j++){
            tempans+=orz.top();
            orz.pop();
        }
        ans=min(ans,tempans);
    }
    cout<<"Case #"<<t<<": "<<ans<<endl;

}

int main(){
    int t;
    cin>>t;
    for (int ttt=1;ttt<=t;ttt++){
        slove(ttt);
    }
}