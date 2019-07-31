#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int NlgN = 100050 * 25;

struct SGT {
    int l,r,sum;
}sgt[NlgN];

int rt[100050];
int n;
const int maxa = 1000000;


// void build(int p, int l, int r) {
//     if(l==r){
//         sgt[p]=cnt[l];
//         return ;
//     }
//     int m=(l+r)>>1;
//     build(p<<1, l, m);
//     build(p<<1|1,m+1,r);
//     sgt[p] = sgt[p<<1|1]+sgt[p<<1];
// }


int mal = 1;

void init() {
    mal=1;
}

int newnode() {
    sgt[mal].l=sgt[mal].r=0;
    sgt[mal].sum=0;
    return mal++;
}
int newnode(int t) {
    if(t != 0) sgt[mal] = sgt[t];
    else return newnode();
    return mal++;
}

void pushup(int rt) {
    sgt[rt].sum = sgt[sgt[rt].l].sum +sgt[sgt[rt].r].sum;
}

void update(int &rt, int l, int r, int a, int x) {
    rt = newnode(rt);
    if(l==r){
        sgt[rt].sum = x;
        return;
    }
    int m=(l+r)>>1;
    if(a<=m) {
        update(sgt[rt].l,l,m,a,x);
    } else {
        update(sgt[rt].r, m+1,r,a,x);
    }
    pushup(rt);
}

int query(int lrt, int rrt, int l, int r, int L, int R) {
    if(L<=l && r <=R) {
        return sgt[rrt].sum-sgt[lrt].sum;
    }
    int ret=0, m=(l+r)>>1;
    if(L<=m){
        ret+=query(sgt[lrt].l, sgt[rrt].l, l,m,L,R);
    }
    if(m<R) {
        ret+=query(sgt[lrt].r, sgt[rrt].r, m+1,r,L,R);
    }
    return ret;
}

int solve(int L,int R, int p, int k) {
    if(query(rt[L-1],rt[R], 1,maxa, p,p) >= k){
        return 0;
    }
    int l=0,r=1000000,m,ret=-1;
    while(l<=r) {
        m = (l+r)>>1;
        if(query(rt[L-1],rt[R], 1,maxa,max(p-m,1),min(p+m,1000000))<k) {
            ret = m; l = m + 1;
        } else {
            r = m - 1;
        }
    }
    // ret [p-ret,p+ret] < k
    return ret+1;
}




int main() {
    int T;
    scanf("%d",&T);
    while(T--){
        int m;init();
        scanf("%d%d",&n,&m);
        rt[0]=0;
        for(int i=1;i<=n;i++){
            int a;
            scanf("%d",&a);
            rt[i]=rt[i-1];
            update(rt[i],1,maxa, a, 1);
        }

        // for(int i=1;i<=5;i++) {
        //     for(int j=i;j<=5;j++)printf("[%d %d] %d||", i, j, query(rt[i-1],rt[j],1,maxa,2,2));
        // }
        // puts("");
        int l,r,p,x=0,k;
        for(int i=1;i<=m;i++){
            scanf("%d%d%d%d",&l,&r,&p,&k);
            // x=solve(l,r,p,k);
            x=solve(l^x,r^x,p^x,k^x);
            printf("%d\n", x);
        }
    }
}


/*

100

6 2
2 6 11 5 12 13
3 5 10 2
1 4 5 3 

10 5
13 3424 4232 4 24 23 42 324 9889 43
2 8 100 5
3 7 200 3
1 10 1000 5
7 10 10000 2
1 5 500 5

10 10
89099 13424 2323 3234 54654 64645 213 3132 43435 54664
1 10 10000 10
1 10 300 2
2 7 300 5
3 5 10 3
2 2 10 1
5 5 1000000 1
1 10 1000000 7
1 10 1000000 10
10 10 1111 1
2 8 10 6
 */