#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,l;
    cin>>n>>l;
    vector<long long>input(n);
    for (auto &i:input)cin>>i;
    long long width=l*8/n;
    width=1<<min(width,30ll);
    map<long long,long long> maps;
    for (auto &i:input)maps[i]++;
    auto ll=maps.begin(),r=maps.begin();
    long long sum=0,ans=0;
    for (long long i=1;i<=width&&r!=maps.end();i++){
        sum+=(*r).second;
        r++;
        ans=max(ans,sum);
        // cout<<ans<<endl;
    }
    while (r!=maps.end()){
        sum-=(*ll).second;
        sum+=(*r).second;
        ll++;
        r++;
        ans=max(ans,sum);
    }
    cout<<n-ans<<endl;
}