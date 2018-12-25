#include <stdio.h>

typedef long long LL;
const int MAXN = 505;
LL lucky[MAXN],unlucky[MAXN];
LL lcmm;
int n,m;
LL l,h;
bool flag=0;

LL gcd(LL a,LL b){
    return b?gcd(b,a%b):a;
}

LL lcm(LL a,LL b){
    return a/gcd(a,b)*b;
}

LL Solve(LL num){
    LL ans = 0;
    for (int i=1;i<(1<<n);i++){
        LL pro = 1;
        int cnt = 0;
        for (int j=0;j<n;j++){
            if ((1<<j)&i){
                pro = lcm(pro,lucky[j]);
                ++cnt;
                if (pro > h)break;
            }
        }
        if (cnt&1){
            if (flag)ans += num/pro;
            else ans += num/pro - num/lcm(pro,lcmm);
        }
        else {
            if (flag)ans -= num/pro;
            else ans -= num/pro-num/lcm(pro,lcmm);
        }
    }
    return ans;
}

int main(){
    while (scanf("%d %d %lld %lld",&n,&m,&l,&h)){
        if (n+m+l+h==0)break;
        lcmm = 1;
        flag = 0;
        for (int i=0;i<n;i++)
            scanf("%lld",&lucky[i]);
        for (int i=0;i<m;i++){
            scanf("%lld",&unlucky[i]);
        	lcmm = lcm(lcmm,unlucky[i]);
            if (lcmm > h){
                flag = true;
            }       
        }
        printf("%lld\n",Solve(h)-Solve(l-1));
    }
}
