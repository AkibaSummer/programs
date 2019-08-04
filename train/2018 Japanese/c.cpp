#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;
 
 
ll input[100001];
 
int main(){
 
    int N;
    ll T;
    scanf("%d %lld",&N,&T);
 
    for(int i = 1; i <= N; i++){
        scanf("%lld",&input[i]);
    }
 
    printf("%lld\n",T/input[1]+1);
 
    if(N == 1){
        return 0;
    }
    ll diff,pre=0;
    for(int i = 2; i <= N; i++){
        pre+=input[i];
        diff=max(diff,input[i]);
        if(pre > T){
            printf("1\n");
            continue;
        }
        printf("%lld\n",(T-pre)/diff+2);
    }
 
    return 0;
}
