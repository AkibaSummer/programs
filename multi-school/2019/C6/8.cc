#include <cstdio>
#include <algorithm>
#include <ctime>
using namespace std;
long long rett[10000];
long long gcd (long long a,long long b) {
    long long r;
    while(b) {
        r= a%b;a=b;b=r;
    }
    return a;
}
int main() {
    int t;
    long long k,s;
    int m,u=0,cnt=0;
    scanf("%d",&t);
    while(t--) {
        cnt=0;
        scanf("%lld%d",&k,&m);
        // printf("%lld",k^1);
        // auto t = clock();
        for(int i=1;i<1000;i++) {
            long long n = k ^ i;
            if(n==0)continue;
            u=0;s=0;
            for(long long j = n+1;;j++) {
                // printf("%lld %lld\n",j,n);
                if(gcd(j,n)==1) {
                    u++;
                }
                if(u==m){
                    s=j;
                    break;
                }
            }
            // printf("%lld %lld\n", s, n);
            if((i+n)==s)rett[++cnt]=n;
        }
        // printf("%ld",clock()-t);
        if(cnt){sort(rett+1,rett+1+cnt);
        printf("%lld\n",rett[1]);}
        else {
            puts("-1");
        }
    }
}