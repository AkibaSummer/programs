#include <cstdio>
#include <cstring>
long long dp[20000];
const long long mod=1e9+7;
int A[2000],S[10005];
int main(){
	int T,N,Q,v,c,m,tot;
	scanf("%d",&T);
	while(T--){m=0;
		scanf("%d%d",&N,&Q);
		for(int i=1;i<=N;i++){
			scanf("%d%d",&v,&c);
			for(int j=0,d=1;j<c;j++,d<<=1){
				A[++m]=d*v;
			}
		}
		int mxS=0;
		for(int i=1;i<=Q;i++){
			scanf("%d",&S[i]);
			if(mxS<S[i])mxS=S[i];
		}
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=1;i<=m;i++){
			for(int j=mxS;j>=A[i];j--){
				if(dp[j-A[i]]){
					dp[j]+=dp[j-A[i]];
					if(dp[j]>mod)dp[j]-=mod;
				}
			}
		}
		for(int i=1;i<=Q;i++)printf("%lld\n",dp[S[i]]);
	}
}