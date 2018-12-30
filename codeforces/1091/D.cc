#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
long long jiecheng[maxn];
long long jcc[maxn];
const int mod = 998244353 ;
int A(int a,int b){
    int ret(1);
    for (int i=a-b+1;i<=a;i++){
        ret*=i;
    }
    return ret;
}
int slove1(int n){
    int ret(0);
    for (int i=0;i<n;i++){
        ret+=A(n,i)*(A(n-i,n-i)-1);
    }
    return ret+1;
}
int main(){
    int n;
    cin>>n;
    jcc[0]=1;
    jiecheng[0]=1;
    for (int i=1;i<=n;i++){
        jiecheng[i]=jiecheng[i-1]*i%mod;
        jcc[i]=jcc[i-1]*(n-i+1)%mod;
    }
    long long ans(1);
    for (int i=0;i<n;i++){
        ans+=jcc[i]*(jiecheng[n-i]-1)%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
    
}