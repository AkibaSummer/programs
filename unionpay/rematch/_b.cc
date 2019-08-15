#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a,int b){
    if (b==0)return a;
    else return gcd(b,a%b);
}

int lcm(int a,int b){
    return max(a,b)*gcd(a,b);
}


void slove(){
    int n,m,p;
    cin>>n>>m>>p;
    int ans=0;
    for (int i=1;i<=sqrt(p);i++){
        if (p%i==0){
            ans+=(n/i)*(m/(p/i))+(n/(p/i))*(m/i)-(n/lcm(i,p/i))*(m/lcm(i,p/i));
            // cout<<i<<' '<<(n/i)*(m/(p/i))<<' '<<(n/(p/i))*(m/i)<<' '<<(n/lcm(i,p/i))*(m/lcm(i,p/i))<<endl;
            // cout<<n/i+m/(p/i)<<endl;
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    int tt;
    while(cin>>tt){
        while(tt--){
            slove();
        }
    }
}