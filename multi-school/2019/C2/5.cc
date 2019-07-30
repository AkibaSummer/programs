#include <cstdio>
long long mod=998244353;
long long fac[5050],fac2[5050], pref[5050], inv[5050],ret[5050], ret2[5050], ret3[5050];
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

long long c(int n,int m){
    return (fac[n] * inv[m])%mod *inv[n-m]%mod;
}

int main() {
    long long n = 3050;
    fac[0]=1;fac2[0]=1; 
    for(int i =1;i<5005;i++){
        fac[i]=(fac[i-1]*i)%mod;
        fac2[i]=(fac2[i-1]*2)%mod;
    }
    inv[5000] = qp(fac[5000],mod-2);
    for(int i=4999;i>=0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
    long long inv4 = inv[4] * fac[3] % mod;

    // printf("%lld\n",c(6,4));

    for(int i=2;i<=n;i++){
        ret[i]=0;
        for(int j =1;j<=i;j++) {
            ret[i]=(c(i,j)* ret[i-j] % mod + ret[i]) % mod;
        }
        // printf("%lld\n", ret[i]);
        ret[i] = (ret[i]  * qp(fac2[i], mod-2)) %mod;
        ret[i] = (ret[i] + (((long long) i) * (i-1) % mod) * inv4) %mod;

        ret[i] = (ret[i] * fac2[i]% mod)  * qp(fac2[i] - 1, mod-2) % mod;

        // printf("%lld\n", ret[i] * 4 % mod);
        // printf("%lld %lld\n", (ret[2] * inv[2] % mod) * 3 % mod , ret[3]);
        ret2[i] = ret2[i-1] + ret[i];
        ret2[i] %=mod;
        ret3[i] = (ret2[i] * inv[i] % mod) * fac[i-1] % mod;
    }

    // for (int i=1;i<=100;i++){
    //     for (int j=1;j<=100;j++){
    //         if ((inv[i]*fac[i-1]%mod)*j%mod==332748118)
    // printf("%d %d %lld\n",i,j,(inv[i]*fac[i-1]%mod)*j%mod);
    //     }
    // }
    // printf("%lld",(inv[7]*fac[6]%mod)*4%mod);
    // for(int i=1;i<=n;i++) {
    //     ret[i]= pref[i] * inv[i] % mod;
    // }
    while(~scanf("%lld",&n)) {
        // if (n >=mod) {
        //     printf("%lld\n",0ll);
        // }
        // else {
            
        // }
        printf("%lld\n",ret3[n]);
    }
}