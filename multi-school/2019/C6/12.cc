#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000050];
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);
        long long res[2]={0}, rnd=0;
        for(int i=n;i>=1;i--){
            res[rnd]+=a[i];
            rnd^=1;
        }
        printf("%lld %lld\n",res[0],res[1]);
    }
}