#include <cstdio>
#include <utility>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int,int>;


vector<int> rnk;
pii task[1000060];

int sgt[3000060<<2];

void build(int p, int l, int r) {
    if(l==r) {
        sgt[p] = rnk[l-1];
        return;
    }
    int m = (l+r)>>1;
    build(p<<1,l,m);
    build(p<<1|1,m+1,r);
    sgt[p] = min(sgt[p<<1], sgt[p<<1|1]);
}

void update(int p, int l, int r, int a, int x) {
    if(l==r) {
        sgt[p] = x;
        return;
    }
    int m = (l+r)>>1;
    if(a<=m) {
        update(p<<1,l,m,a,x);

    } else {
        update(p<<1|1,m+1,r,a,x);
    }
    sgt[p] = min(sgt[p<<1], sgt[p<<1|1]);
    // printf("[%d, %d]")
}

int query(int p, int l, int r, int L) {
    if(L<=l) {
        return sgt[p];
    }
    int m = (l+r)>>1;
    if(m<L) {
        return query(p<<1|1,m+1,r,L);
    } else {
        return min(query(p<<1, l, m, L), query(p<<1|1,m+1,r,L));
    }
}


int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    rnk.reserve(q * 2 + 3);
    for(int i=1;i<=q;i++) {
        scanf("%d%d",&task[i].first, &task[i].second);
        rnk.push_back(task[i].second);
        // rnk.push_back(task[i].second-1);
        rnk.push_back(task[i].second+1);
    }

    rnk.push_back(1);
    rnk.push_back(n);
    rnk.push_back(n+1);

    sort(rnk.begin(), rnk.end());
    rnk.erase(unique(rnk.begin(), rnk.end()), rnk.end());

    int m = rnk.size();
    build(1, 1, m);

    auto getrnk = [&](int t) {
        return lower_bound(rnk.begin(), rnk.end(), t) - rnk.begin() + 1;
    };
    // int u = 1;
    // for(auto x:rnk) {
    //     printf("~%d %d\n", x, query(1,1,m,u++));
    // }
    // puts("");

    for(int i=1;i<=q;i++) {
        if(task[i].first == 1) {
            update(1,1,m, getrnk(task[i].second), n+1);
            // printf("[%d...]",getrnk(task[i].second));
        } else {
            int ret = query(1,1,m,getrnk(task[i].second));
            if (ret == n+1) {
                printf("-1\n");
            } else {
                printf("%d\n",ret);
            }
            // printf("[%d...]",getrnk(task[i].second));
        }
    }
}

/*

5 10
1 5
2 5
2 4
2 3
1 3
2 3
1 1
1 2
2 1
2 4

3 50
2 1
2 2
2 3
2 4
2 0
1 1
2 1
2 2
2 3
2 4
2 0
1 2 
2 1
2 2
2 3
2 4
2 0
1 3
2 1
2 2
2 3
2 4
2 0

*/