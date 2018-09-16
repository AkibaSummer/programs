#include <iostream>
#include <string>
using namespace std;

const long long mod =1000000007;
typedef long long ll;
ll mod_pow(ll x, ll n, ll mod)
{
    ll res = 1;
    while (n) {
        if (n & 1)
            res = res*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}
int main(){
    int T;
    long long N,b;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        N=0;b=1;
        for(int i=0;i<s.size();i++){
//            N=(((s[i]-'0')*b%mod)+N)%mod;
//            b=b*10%mod;
            N=(N*10+s[i]-'0')%(mod-1);
        }
        printf("%lld\n",mod_pow(2,(N-1+mod)%mod,mod));
    }

    return 0;
}