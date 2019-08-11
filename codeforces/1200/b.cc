#include <bits/stdc++.h>
using namespace std;

#define int long long

void slove(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> h(n);
    for (auto &i:h)cin>>i;
    for (int i=1;i<n;i++){
        if (h[i-1]+m<h[i]-k){
            puts("NO");
            return ;
        }
        else {
            m+=h[i-1]-max(0ll,(h[i]-k));
        }
    }
    puts("YES");
}

signed main(){
    int tt;
    cin>>tt;
    while(tt--){
        slove();
    }
}