#include<bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;

long long sqr(long long n){
    return n*n % mod;
}

long long get_2(long long l,long long r){
    l=l-1;
    long long rr=r*(r+1)%mod*(2*r+1)%mod;
    while (rr%6)rr+=mod;
    rr/=6;
    long long ll=l*(l+1)%mod*(2*l+1)%mod;
    while (ll%6)ll+=mod;
    ll/=6;
    long long ret=(rr+mod-ll)%mod;
    // cout<<l+1<<' '<<r<<' '<<ret<<endl;
    return ret;
}

long long get2(long long n){
    long long i,j;
    long long ans=0;
    for (i=1;i<=n;i=j+1){
        long long item=n/i;
        j=n/item;
        ans+=get_2(i,j)*item;
        ans%=mod;
        // cout<<ans<<endl;
    }
    // cout<<ans<<endl;
    return ans;
}

long long get1(long long n){
    long long ret=sqr(n)*(n+1)%mod;
    if (ret%2)return (ret+mod)/2;
    else return ret/2;

}

long long get(long long n){
    return (get1(n)+mod-get2(n))%mod;
}

int main(){
    // cout<<get2(10)<<endl;
    long long n,m;
    cin>>n>>m;
    cout<<(get(n)*get(m)%mod)<<endl;
}