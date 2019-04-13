#include <bits/stdc++.h>
using namespace std;

long long getmin(long long q,long long a,long long b){
    long long ans=1ll<<60;
    for (int i=0;i<=(q+2)/3+1;i++){
        ans=min(ans,i*b+a*((max(0ll,q-i*3)+1)/2));
    }
    return ans;
}

void slove(){
    long long n,m,k,a,b,c;
    cin>>n>>m>>k>>a>>b>>c;
    long long ans = 1ll<<60;
    for (int i=0;i<=k;i++){
        ans=min(ans,c*i+getmin(n+k-i,a,b)+getmin(m+k-i,a,b));
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        slove();
    }
}