#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin>>n;
    vector<int>output(2*n);
    if (n==1){
        puts("YES");
        puts("1 2");
    }
    else {
        if (n%2){
            for (int i=0;i<n;i++){
                output[2*i]=2*i+1;
                output[(2*i+n)%(2*n)]=2*i+2;
            }
            puts("YES");
            for (auto &i:output)cout<<i<<' ';
        }
        else puts("NO");
    }
}