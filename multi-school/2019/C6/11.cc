#include <bits/stdc++.h>
using namespace std;

typedef __int128 Bigint;
typedef long long ll;
const int maxn = 50000;
const ll mod = 1000000007;

char str[maxn+5];
ll unknownpos[25];
Bigint unknownmat[25][25];
ll unknownmod[25],unknownm[25];

inline void slove(){
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    scanf("%s",str+1);
    ll nowmodmod=1,nowmodm=1;
    ll summodmod=0,summodm=0;
    int unknownnum=0;
    for (int i=n;i>=1;i--){
        if (str[i]=='?'){
            if (unknownnum<21){
                unknownnum++;
                unknownmod[unknownnum]=nowmodmod;
                unknownm[unknownnum]=nowmodm;
                unknownpos[unknownnum]=i;
                for (int j=0;j<m;j++){
                    for (int k=0;k<=9;k++){
                        unknownmat[unknownnum][(j+k*nowmodm)%m]+=unknownmat[unknownnum-1][j];
                    }
                }
            }
        }
        else {
            summodm=(summodm+nowmodm*(str[i]-'0'))%m;
            summodmod=(summodmod+nowmodmod*(str[i]-'0'))%mod;
        }
        nowmodm=nowmodm*10%m;
        nowmodmod=nowmodmod*10%mod;
    }
    while(q--){
        long long que;
        long long ans = summodmod;
        scanf("%lld",&que);
        if (unknownmat[unknownnum][m-summodm]<que){
            puts("-1");
            continue;
        }
        for (int i=unknownnum;i>=1;i--){
            for (int j=0;j<=9;j++){
                if (unknownmat[i-1][m-summodm]<que){
                    que-=unknownmat[i-1][m-summodm];
                    summodm=(summodm+unknownm[i])%m;
                    ans=(ans+unknownmod[i])%mod;
                    continue;
                }
                else {
                    break;
                }
            }
        }
        printf("%lld\n",ans);
    }

}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        slove();
    }
}