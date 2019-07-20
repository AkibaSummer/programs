#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int isprime(int n){
    for (int i=sqrt(n);i>=2;i--){
        if (n%i==0)return 0;
    }
    return 1;
}

int main(){
    int n;
    cin>>n;
    int ans;
    for (ans=n;ans;ans++){
        if (isprime(ans))break;
    }
    cout<<ans<<endl;
    for (int i=1;i<n;i++){
        cout<<i<<' '<<i+1<<endl;
    }
    cout<<1<<' '<<n<<endl;
    ans-=n;
    while (ans--){
        cout<<ans+1<<' '<<n-ans-1<<endl;
    }
}