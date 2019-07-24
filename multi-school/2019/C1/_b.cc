#include<cstdio>
#include <cstring>
#include <algorithm>
int seg[1000050<<2][30],fff;
void insert(int *a, int x) {
    for(int i =29;i>=0;i--) {
        if((x>>i)&1) {
            if(!a[i]) {
                a[i] = x;
                break;
            }
            x ^=a[i];
        }
    }
    return ;
}
void merge(int *a, int *b) {
    for(int i=29;i>=0;i--){
            // printf("[%d]",b[i]);
        if (!a[i]&&b[i]) {
            a[i]=b[i];
            //insert(a,b[i]);
        }
    }
}
int a[1000050], n, m;
void build(int p, int l, int r) {
    if (l==r) {
        // printf("%d %d\n",l,r);
        for(int i=0;i<=29;i++){
            seg[p][i]=0;
        }
        for(int i=29;i>=0;i--){
            if((a[l]>>i)&1) {
                seg[p][i]=a[l];
                break;
            } 
        }
        return;
    }
    int m=(l+r)>>1;
    build(p<<1,l,m);
    build(p<<1|1, m+1,r);
    for(int i = 0;i<=29;i++) {
        seg[p][i]=seg[p<<1][i];
    }
    merge(seg[p],seg[p<<1|1]);
}
int ret[32];
void query(int p, int l, int r, int L, int R) {
    // printf("%d %d\n",l, r);
    if (l > r) {
        return;
    } 
    if(L<=l && r <= R) {
        // printf("qwq");
        merge(ret,seg[p]);
        return;
    }
    int m = (l+r)>>1;
    if (R > m) {
        query(p<<1|1,m+1,r, L,R);
    }
    if (L <=m) {
        query(p<<1, l,m, L,R);
    }
}

void update(int p, int l, int r, int a, int x) {
    if (l==r) {
        insert(seg[p],a);
        return;
    }
    int m = (l+r)>>1;
    if(l<=m) {
        update(p<<1,l,m,a,x);
    } else {
        update(p<<1|1,m+1,r,a,x);
    }
}

int sux(int *a) {
    int ret=0;
    for(int i = 29;i>=0;i--) {
        if(((ret>>i)&1)==0) {
            if(a[i]){
                ret ^=a[i];
            }
        }
    }
    return ret;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        // printf("...");
        for(int i =1;i<=n;i++){
            // a[i]=1;
            scanf("%d",&a[i]);
            // printf("%d",a[i]);
        }
        fff=n;
        
        int s=m+n;
        int res=0;
        //int nn =n;
        build(1,1,s);
        for(int i =1;i<=m;i++){
            int o;
            scanf("%d",&o);
            if (o) {
                int x;
                scanf("%d",&x);
                x=x^res;
                update(1,1,s,++n, x);
            } else {
                int l, r;
                scanf("%d%d",&l,&r);
                l=(l^res)%n+1;
                r=(r^res)%n+1;
                if(l>r) {
                    std::swap(l,r);
                }
                // printf("qwq[%d,%d]\n",l,r);
                memset(ret,0,sizeof(ret));
                query(1,1,s,l,r);
                printf("%d\n",res=sux(ret));
            }
        }
    }
}
/*
1
3 3
0 1 2

0 1 1
 */