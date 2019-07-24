#include <cstdio>
long long mod=1e6+3;
long long fac[2000005];
int main() {
    long long n;
    fac[0]=1;
    for(int i =1;i<mod;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    while(~scanf("%lld",&n)) {
        if (n >=mod) {
            printf("%lld\n",0ll);
        }
        else {
            printf("%lld\n",fac[n]);
        }
    }
}