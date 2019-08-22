#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

#define int long long

const int mod=998244353;

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}

void slove(){
    int n;
    cin>>n;
    vector<pair<int,int>> input(n);
    vector<int> A(n+1);
    A[1]=1;
    for (int i=2;i<=n;i++){
        A[i]=A[i-1]*i%mod;
    }
    for (auto &i:input){
        cin>>i.first>>i.second;
    }
    sort(input.begin(),input.end());
    int bad=0,tmp=1;
    int pre=-1,cnt=1;
    for (int i=1;i<n;i++){
        if (input[i].first==input[i-1].first)cnt++;
        else {
            tmp*=A[cnt];
            tmp%=mod;
            cnt=1;
        }
    }
    cerr<<tmp<<endl;
    tmp*=A[cnt];
    tmp%=mod;
    bad+=tmp;
    tmp=1;
    cnt=1;
    int flag = 0;
    for (int i=1;i<n;i++){
        if (input[i]==input[i-1])cnt++;
        else {
            tmp*=A[cnt];
            tmp%=mod;
            cnt=1;
        }
        if (input[i].first<input[i-1].first||input[i].second<input[i-1].second)flag=1;
    }
    cerr<<tmp<<endl;
    tmp*=A[cnt];
    tmp%=mod;
    if (!flag)bad-=tmp;
    tmp=1;
    cnt=1;
    sort(input.begin(),input.end(),cmp);
    for (int i=1;i<n;i++){
        if (input[i].second==input[i-1].second)cnt++;
        else {
            tmp*=A[cnt];
            tmp%=mod;
            cnt=1;
        }
    }
    cerr<<tmp<<endl;
    tmp*=A[cnt];
    tmp%=mod;
    bad+=tmp;    
    cout<<(A[n]+3*mod-bad)%mod<<endl;
}

signed main(){
    int t;
    // cin>>t;
    t=1;
    while(t--){
        slove();
    }
}