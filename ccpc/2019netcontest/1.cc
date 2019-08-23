#include <cstdio>

int main() {
    int T;
    long long A,B;
    scanf("%d",&T);
    while(T--) {
        scanf("%lld%lld",&A,&B);
        if((A&B)!=0){
            printf("%lld\n",A&B);
        } else {
            long long C = (A^B)&0xffffffffLL;
            printf("%lld\n",C&(-C));
        }
    }
}