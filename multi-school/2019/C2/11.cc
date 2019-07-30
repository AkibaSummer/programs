#include <cstdio>
#include <cstring>
#include <algorithm>
int sgt[100050*4][50],sgl[100050*4],a[100050],tmp[105],res[105];
bool cmp (int l,int r) {
    return l>r;
}
void build(int p,int l, int r) {
    if(l==r){
        sgl[p]=1;
        sgt[p][0]=a[l];
        return;
    }
    int m=(l+r)>>1;
    build(p<<1,l,m);
    build(p<<1|1,m+1,r);
    std::merge(sgt[p<<1],sgt[p<<1]+sgl[p<<1], sgt[p<<1|1],sgt[p<<1|1]+sgl[p<<1|1],tmp,cmp);
    sgl[p]=sgl[p<<1]+sgl[p<<1|1];
    if(sgl[p]>48){
        sgl[p]=48;
    }
    for(int i=0;i<sgl[p];i++){
        sgt[p][i]=tmp[i];
    }
    return;
}
void print(int *x,int l){
    printf("[");
    for(int i=0;i<l;i++){
        printf("%d ",x[i]);
    }
    printf("]");
}
void gor(int p,int l, int r, int L,int R, int *ret, int &lll) {
    // printf("[%d %d]",l,r);
    if(L<=l && r <=R) {
        // print(sgt[p],sgl[p]);
        // printf("+");
        // print(ret,lll);
        std::merge(sgt[p],sgt[p]+sgl[p],ret,ret+lll,tmp,cmp);
        lll+=sgl[p];
        if(lll>48){
            lll=48;
        }
        for(int i=0;i<lll;i++){
            ret[i]=tmp[i];
        }
        // printf("=");
        // print(ret,lll);
        // puts("");
        return;
    }
    int m=(l+r)>>1;
    if(L<=m){
        gor(p<<1,l,m,L,R,ret,lll);
    }
    if(m<R){
        gor(p<<1|1,m+1,r,L,R,ret,lll);
    }
    return;
}
long long cal(int *ret, int lll) {
    if(lll<=2){
        return -1;
    }
    int xxx = lll-2;
    for(int i=0;i<xxx;i++){
        if(0ll+ret[i+1]+ret[i+2]>ret[i]){
            return 0ll+ret[i+1]+ret[i+2]+ret[i];
        }
    }
    return -1;
}
int main() {
    int n,q;
    while (scanf("%d%d", &n, &q)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        build(1,1,n);
        // puts("...");
        // return 0;
        for(int i=1;i<=q;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            memset(res,0,sizeof(int)*55);
            int lll=0;
            gor(1,1,n,l,r,res,lll);
            // printf("%d[",lll);
            // for(int i=0;i<lll;i++){
            //     printf("%d ",res[i]);
            // }
            // printf("]\n");
            printf("%lld\n",cal(res, lll));
        }
    }
}

/*
3 1
1 1 2 
1 3

2 1
1 2
1 2
 */