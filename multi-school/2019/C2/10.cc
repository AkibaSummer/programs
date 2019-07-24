#include <cstdio>
long long mod=998244353;
long long fac[5050],fac2[5050], pref[5050], inv[5050],ret[5050];
long long qp(long long a, long long b) {
    long long ret=1;
    while(b) {
        if(b&1) {
            ret = ret * a % mod;
        }
        a = a*a %mod;b>>=1;
    }
    return ret;
}
int main() {
    long long n;
    fac[0]=1;fac2[1]=1; 
    for(int i =1;i<5005;i++){
        fac[i]=(fac[i-1]*i)%mod;
        fac2[i+1]=(fac2[i]*2)%mod;
        pref[i]=(pref[i-1]+fac2[i-1])%mod;
    }
    inv[5000] = qp(fac[5000],mod-2);
    for(int i=4999;i>=0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
    for (int i=1;i<=100;i++){
        for (int j=1;j<=100;j++){
            if ((inv[i]*fac[i-1]%mod)*j%mod==332748118)
    printf("%d %d %lld\n",i,j,(inv[i]*fac[i-1]%mod)*j%mod);
        }
    }
    printf("%lld",(inv[7]*fac[6]%mod)*4%mod);
    for(int i=1;i<=n;i++) {
        ret[i]= pref[i] * inv[i] % mod;
    }
    while(~scanf("%lld",&n)) {
        // if (n >=mod) {
        //     printf("%lld\n",0ll);
        // }
        // else {
            
        // }
        printf("%lld\n",ret[n]);
    }
}