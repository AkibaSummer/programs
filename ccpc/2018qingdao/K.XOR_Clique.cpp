#include <bits/stdc++.h>
using namespace std;
inline int bits(int n){
    int ret(0);
    while(n){
        ++ret;
        n>>=1;
    }
    return ret;
}
int main(){
    int t,q1;
    cin>>t;
    while(t--){
        int n,ans(0);
        cin>>n;
        vector<int>maxb(50);
        for (int i=1;i<=n;i++){
            cin>>q1;
            ++maxb[bits(q1)];
        }
        for (auto &i:maxb)ans=max(ans,i);
        cout<<ans<<endl;
    }
    return 0;
}