#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;


const int NN = 1e7, NNllgoN = 1e6;
int nprim[NN+50],prim[NNllgoN], pc=0;
void sieve() {
    for(int i = 2;i<=NN;i++){
        if(!nprim[i]) {
            prim[++pc]=i;
            for(int j=i+i;j<=NN;j+=i) {
                nprim[j]=1;
            }
        }
    }
}

int solve(long long n) {
    long long x = sqrt(n);
    if(n==1){
        return 123123;
    }

    if(x * x == n) {
    // printf("222 %lld\n",x);
        return solve(x) * 2;
    }
    if((x+1) * (x+1) == n) {
        return solve(x+1) * 2;
    }

    x = pow((double)n, 1.0/3);
    if(x * x * x == n) {
    // printf("333 %lld\n",x);
        return solve(x) * 3;
    }
    if((x+1) * (x+1) * (x+1) == n) {
        return solve(x+1) * 3;
    }

    x = pow((double)n, 1.0/4);
    // printf("%lld\n",x);
    if(x * x * x * x == n) {
        return solve(x) * 4;
    }
    if((x+1) * (x+1) * (x+1) * (x+1) == n) {
        return solve(x+1) * 4;
    }


    x = pow((double)n, 1.0/5);
    // printf("%lld\n",x);
    if(x * x * x * x * x == n) {
        return solve(x) * 5;
    }
    if((x+1) * (x+1) * (x+1) * (x+1) * (x+1) == n) {
        return solve(x+1) * 5;
    }


    long long y,z;
    for(int i=1;prim[i]<=x;i++) {
        // printf("%d",i);
        y = prim[i];
        if(n%y==0) {
            int ret = 0;
            while(n%y==0) {
                ret++;
                n/=y;
            }
            // printf("%d %lld\n",ret, n);
            return min(solve(n), ret);
        }
    }
    return 1;
}

int main() {
    int T;
    sieve();
    // printf("%d %d", prim[1], prim[2]);
    scanf("%d",&T);
    while(T--) {
        long long ret;
        scanf("%lld",&ret);
        if(ret==1) {
            printf("1\n");
        } else {
        printf("%d\n",solve(ret));
        }
    }
}