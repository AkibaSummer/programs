#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
inline void fast(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void slove(){
    int a,b,n;
    cin>>a>>b>>n;
    n%=3;
    if (n==0)cout<<a<<endl;
    else if (n==1)cout<<b<<endl;
    else cout<<(a^b)<<endl;
}

int main(){
    // fast();
    int tt;
    cin>>tt;
    // tt=1;
    while(tt--){
        slove();
    }
}