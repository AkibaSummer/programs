#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--){
        long long l,r,x;
        cin>>l>>r>>x;
        cout<<r/x-(l-1)/x;
        puts("");
    }
}