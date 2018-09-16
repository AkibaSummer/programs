#include <cstdio>
#include <algorithm>
using namespace std;
long long a,b,c,d,v,t;
long long gcd(long long a,long long b){
	long long r;
	while(b){
		r=a%b;a=b;b=r;
	}
	return a;
}
long long A[3000000];
int main(){
	int T,m;long long res;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&v,&t);
		res=(t/a)*b+(t/c)*d-1+b+d;
		//printf("%lld\n",res);
		long long lcm=a*c/gcd(a,c);
		m=0;
		for(long long i=lcm;i>=0;i-=a){
			A[++m]=i;
		}
		for(long long i=lcm-c;i>0;i-=c){
			A[++m]=i;
		}
		sort(A+1,A+1+m);
		//printf("%d\n",m);
		//for(int i=1;i<=m;i++){
		//	printf("%lld ",A[i]);
		//}
		//puts("");
		long long circ=0;
		for(int i=2;i<=m;i++){
			if(A[i]-A[i-1]>=v+1)circ++;
		}
		//printf("%lld\n",circ);
		res-=circ*(t/lcm);
		//printf("%lld\n",res);
		t%=lcm;
		for(int i=2;A[i]<=t&&i<=m;i++){
			if(A[i]-A[i-1]>=v+1)res--;
		}
		printf("%lld\n",res);
	}
	return 0;
}
/*
222
8 2 5 1 2 0
10 2 5 1 2 10
 */