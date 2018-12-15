#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> orz(n/2);
    for (auto &i:orz)
        cin>>i;
    vector<long long> output(n);
    output[0]=0;
    output[n-1]=orz[0];
    for (int i=1;i<n/2;i++){
        output[i]=max(output[i-1],orz[i]-output[n-i]);
        output[n-i-1]=orz[i]-output[i];
    }
    for (auto i:output)cout<<i<<' ';
}