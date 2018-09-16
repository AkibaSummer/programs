#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	int n,m;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int mx=m,mi=max((int)(ceil((double)(m)/(n-m+1))),min(m,1));
		printf("%d %d\n",mx,mi);
	}
	return 0;
}