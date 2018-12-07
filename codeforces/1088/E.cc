#include <iostream>
#include <vector>
using namespace std;
int a[300005],k;
long long dp[300005],ans=-1e9;
vector<int> v[300005];
void dfs(int node,int p,bool f){
    dp[node]=a[node];
    for (int u:v[node]){
        if (u!=p){
            dfs(u,node,f);
            dp[node]+=max(dp[u],0LL);
        }
    }
    if (f)
    ans=max(ans,dp[node]);
    else if (dp[node]==ans){
        dp[node]=0;
        k++;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for (int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0,1);
    dfs(1,0,0);
    printf("%I64d %d",ans*k,k);
}