#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long tot[100005];
long long n,m;
bool judge(long long minn){
    if (minn==0)return true;
    memset(tot,0,sizeof(long long)*(n+2));
    long long mm=m;
    for (long long i=1;i<=n;i++){
        if (mm<=0)break;
        mm--;
        tot[i]+=a[i];
        if (tot[i]<minn){
            long long num=(minn-tot[i]+a[i]-1)/a[i];
            if(num*2 < mm)return false;
            mm-=num*2;
            tot[i]+=num*a[i];
            tot[i+1]+=num*a[i+1];
        }
    }
    if (mm>=0){
        if (tot[n]>=minn)return true;
        else return false;
    }
    else if(mm<0){
        return false;
    }
}
void slove(){
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    long long l=0,r=1e18,res=0;
    while (l<r){
        long long m=(l+r)>>1;
        if (judge(m)){
            l=m+1;res=l;
        }
        else r=m-1;
    }
    printf("%lld\n",res);

}
int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        slove();
    }
}
/*
2
4 8
3 2 6 6
3 9
10 10 1
*/