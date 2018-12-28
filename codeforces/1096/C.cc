#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    double orz;
    int t;
    cin>>t;
    while (t--){
        int k;
        cin>>k;
        int ans=180/gcd(180,k);
        while ((double)(ans-2)/ans*180<k)ans*=2;
        cout<<ans<<endl;
    }
}