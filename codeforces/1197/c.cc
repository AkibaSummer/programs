#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>input(n),calc(n);
    for (auto&i:input) cin>>i;
    for (int i=1;i<n;i++){
        calc[i]=input[i]-input[i-1];
    }
    // calc[0]=input[0];
    sort(calc.begin(),calc.end());
    long long ans=input[n-1]-input[0];
    // for (auto i:calc)cout<<i<<' ';
    for (int i=n-1;i>n-k;i--){
        ans-=calc[i];
    }
    cout<<ans<<endl;  
}