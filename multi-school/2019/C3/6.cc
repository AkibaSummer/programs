#include <cstdio>

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>

using namespace std;
#define me(x,y) memset(x,y,sizeof x)
#define MIN(x,y) x < y ? x : y
#define MAX(x,y) x > y ? x : y
typedef long long ll;
const int maxn = 1e5+10;
const double INF = 0x3f3f3f3f;
const int MOD = 1e6;
const double eps = 1e-06;

ll Mul(ll a,ll b,ll p){  // a*b%p
    ll ans = 0;
    a %= p;
    b %= p;
    if(b < 0) a = -a,b = -b;
    while(b){
        if(b&1) ans = (ans+a)%p;
        b >>= 1;
        a = (a+a)%p;
    }
    ans = (ans+p)%p;
    return ans;
}

// ll Quick_Pow(ll a,ll b,ll p){   //a^b%p
//     ll ans = 1;
//     while(b){
//         if(b&1) ans = Quick_Multiply(ans,a,p);
//         b >>= 1;
//         a = Quick_Multiply(a,a,p);
//     }
//     return ans;
// }

// bool Miller_Rabin(ll n){    //Miller_Rabin
//     ll i,j,a,x,y,t,u,s = 10;
//     if(n == 2 || n == 3) return true;
//     if(n < 2 || !(n&1)) return false;
//     for(t = 0,u = n-1;!(u&1); t++,u>>=1);   //n-1 = u*2^t
//     for(i = 0; i < s; i++){
//         a = rand()%(n-1)-1;
//         x = Quick_Pow(a,u,n);   //a^u
//         for(j = 0; j < t; j++){
//             y = Quick_Multiply(x,x,n);  //x^2
//             if(y == 1 && x != 1 && x != n-1) return false;  //二次探测
//             x = y;
//         }
//         if(x != 1) return false;    //费马小定理
//     }
//     return true;
// }
ll Quick_Multiply(ll a, ll b, ll P) {
    ll t = (a*b - (ll)((long double)a/P*b+1e-8)*P); 
    return t<0 ? t+P : t;
}
ll Pow(ll a, ll b, ll P) {
    ll ans=1; a%=P;
    for(; b; b>>=1, a=Mul(a, a, P))
        if(b&1) ans=Mul(ans, a, P);
    return ans;
}
bool witness(ll a, ll n, ll u, int t) { 
    ll x=Pow(a, u, n), y=x;
    for(int i=1; i<=t; i++) { 
        x=Mul(x, x, n);
        if(x==1 && y!=1 && y!=n-1) return true;
        y=x;
    }
    return x!=1;
}

ll randd(){
    return (((long long)rand())<<29)+rand();
}

bool Miller_Rabin(ll n) { 
    if(n==2) return true;
    if(n<=1 || !(n&1)) return false;
    ll u=n-1, t=0;
    while(!(u&1)) u>>=1, t++;
    for(int i=1; i<=25; i++) 
        if(witness(randd()%(n-1)+1, n, u, t)) return false;
    return true;
}

// int main(){
    
//     //freopen("E:/TanJX/in.txt","r",stdin);
//     //freopen("E:/TanJX/out.txt","w",stdout);
//     int n;
//     while(cin>>n){
//         int sum = 0;
//         ll x;
//         for(int i = 1; i <= n; i++){
//             scanf("%lld",&x);
//             if(Miller_Rabin(x)) sum++;
//         }
//         cout<<sum<<endl;
//     }
//     return 0;
// }


int main() {
    int t;
    scanf("%d",&t);
    long long P;
    // cout<<Miller_Rabin(22801763489)<<endl;
    while(t--) {
        scanf("%lld",&P);
            long long ret = 1;
            for(ll i=P-2;;i-=2) {
                if (Miller_Rabin(i)) {
                    printf("%lld\n",ret);
                    break;
                }
                ret = Mul(ret,Pow(i, P-2, P),P);
                // ret %=P;
                ret = Mul(ret,Pow(i-1, P-2, P),P);
                // ret *= Quick_Pow(i-1, P-2, P);
                // ret %=P;
            }
    }
}