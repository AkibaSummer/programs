#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const long long mod = 998244353 ;

int main(){
    int w,h;
    cin>>w>>h;
    long long ans = 2;
    for (int i=1;i<=w;i++){
        ans*=2;
        ans%=mod;
    }for (int i=2;i<=h;i++){
        ans*=2;
        ans%=mod;
    }
    cout<<ans<<endl;
}