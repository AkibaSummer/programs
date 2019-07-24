#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int p[1000050][32],pos[1000050][32];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,x;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            memcpy(p[i],p[i-1],sizeof(p[i]));
            memcpy(pos[i],pos[i-1],sizeof(pos[i]));
            scanf("%d",&x);int ti=i;
            for(int j=30;j>=0;j--){
                if(x&(1<<j)) {
                    if(!p[i][j]){p[i][j]=x;pos[i][j]=ti;break;}
                    if(pos[i][j] < ti) {
                        swap(pos[i][j],ti);
                        swap(p[i][j],x);
                    }
                    x^=p[i][j];
                }
            }
        }
        int res=0;
        for(int i =1;i<=m;i++) {
            int o;
            scanf("%d",&o);
            if (o) {
                int x;
                scanf("%d",&x);
                x=x^res;int ti=++n;
                memcpy(p[n],p[n-1],sizeof(p[n]));
                memcpy(pos[n],pos[n-1],sizeof(pos[n]));
                for(int j=30;j>=0;j--){
                    if(x&(1<<j)) {
                        if(!p[n][j]){p[n][j]=x;pos[n][j]=ti;break;}
                        if(pos[n][j] < ti) {
                            swap(pos[n][j],ti);
                            swap(p[n][j],x);
                        }
                        x^=p[n][j];
                    }
                }

            } else {
                int l, r;
                scanf("%d%d",&l,&r);
                l=(l^res)%n+1;
                r=(r^res)%n+1;
                if(l>r) {
                    std::swap(l,r);
                }
                // printf("qwq[%d,%d]\n",l,r);
                res=0;
                for(int j=30;j>=0;j--) {
                    if(pos[r][j]>=l&&(res^p[r][j])>res) res^=p[r][j];
                }
                printf("%d\n",res);
            }
        }
    }
}