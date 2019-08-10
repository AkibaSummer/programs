#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) (x &(-x))

long long b[200050],c[200050],n,m;
long long add(long long x, long long i) {
    while(x <=n) {
        b[x]+=i;
        c[x]++;
        x+=lowbit(x);
    }
}
long long sum(long long x) {
    long long ret=0;
    while(x) {
        ret+=b[x];
        x-=lowbit(x);
    }
    return ret;
}
long long sum2(long long x) {
    long long ret=0;
    while(x) {
        ret+=c[x];
        x-=lowbit(x);
    }
    return ret;
}

struct u {
    long long x,id;
}a[200050];
long long e[200050];

long long rk[200050];

void slove(){
    scanf("%lld%lld",&n,&m);
    for (long long i=1;i<=n;i++){
        scanf("%lld",&a[i].x);
        a[i].id=i,e[i]=a[i].x;
    }
    sort(a+1,a+1+n,[](u &x, u&y) -> bool {
        return x.x < y.x;
    });
    memset(b,0,sizeof(long long)*(n+1));
    memset(c,0,sizeof(long long)*(n+1));
    for(long long i=1;i<=n;i++) {
        rk[a[i].id] = i;
    }
    
    for(long long i=1;i<=n;i++){
        long long l=0,r=n,mi, ret=0;
        while(l<=r) {
            mi=((l+r)>>1);
            if(sum(mi) <= m - e[i]) {
                ret = mi; l = mi+1;
            } else {
                r = mi-1;
            }
        }
        printf("%lld ",i-1-sum2(ret));
        add(rk[i], e[i]);
    }
    puts("");

}

int main(){
    slove();
}

/*
7 15  
1 2 3 4 5 6 7  
5 100  
80 40 40 40 60
 */