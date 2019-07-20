#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
const int maxn=505;
const ll mod = 998244353;
ll dp[maxn][maxn];
ll input[maxn];
 
ll getans(int l,int r){
    if (dp[l][r-l+1])return dp[l][r-l+1];
    int minnum=maxn,minpos;
    for (int i=l;i<=r;i++){
        if (input[i]<minnum){
            minnum=input[i];
            minpos=i;
        }
    }
    ll lsum=0,rsum=0;
    for (int i=l;i<=minpos;i++){
        lsum+=getans(l,i-1)*getans(i,minpos-1);
        lsum%=mod;
    }
    for (int i=minpos;i<=r;i++){
        rsum+=getans(minpos+1,i)*getans(i+1,r);
        rsum%=mod;
    }
    return dp[l][r-l+1]=lsum*rsum%mod;
}
 
int main(){
    for (int i=0;i<maxn;i++){
        dp[i][1]=1;
        dp[i][2]=2;
        dp[i][0]=1;
    }
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>input[i];
    }
    cout<<getans(1,n)<<endl;
}