#include <algorithm>
#include <cstdio>
#include <cstring>
#define lowbit(x) ((x) & -(x))
using namespace std;

const int N = 100050, logN = 18;

struct SGT {
    int l, r, sum;
} sgt[N * logN * logN];

int mal = 1;

void init() { mal = 1; }

int newnode() {
    sgt[mal].sum = sgt[mal].l = sgt[mal].r = 0;
    return mal++;
}

int newnode(int rt) {
    if (rt) {
        sgt[mal] = sgt[rt];
    } else {
        sgt[mal].sum = sgt[mal].l = sgt[mal].r = 0;
    }
    return mal++;
}

int root[N];
int rts[50][logN + 10];
int n;
int extract(int x) {
    int sz = 0;
    while (x <= n) {
        rts[0][++sz] = x;
        x += lowbit(x);
    }
    return sz;
}

int extracts(int x) {
    int sz = 0;
    while (x) {
        rts[0][++sz] = x;
        x -= lowbit(x);
    }
    return sz;
}

void update(int &rt, int l, int r, int a, int x) {
    rt = newnode(rt);
    if (l == r) {
        sgt[rt].sum += x;
        return;
    }
    int m = (l + r) >> 1;
    if (a <= m) {
        update(sgt[rt].l, l, m, a, x);
    } else {
        update(sgt[rt].r, m + 1, r, a, x);
    }
    sgt[rt].sum = sgt[sgt[rt].l].sum + sgt[sgt[rt].r].sum;
}

int query(int rt[][logN + 10], int sz, int l, int r, int k) {
    // printf("[%d %d]", l, r);
    int *nxrt = rt[1], *tsrt = rt[0];
    if (k <= l) {
        // printf("qwq");
        int sum = 0;
        if (l == r) {
            for (int i = 1; i <= sz; i++) {
                sum += sgt[tsrt[i]].sum;
            }
            // printf("sum%d...",sum);
            return sum == 1 ? -1 : l;
        }

        int m = (l + r) >> 1;
        for (int i = 1; i <= sz; i++) {
            sum += sgt[sgt[tsrt[i]].l].sum;
        }

        // printf("%d\n", sum);

        if (sum == (m - l + 1)) {
            sum = 0;
            for (int i = 1; i <= sz; i++) {
                sum += sgt[sgt[tsrt[i]].r].sum;
            }
            if (sum == (r - m)) {
                return -1;
            } else {
                for (int i = 1; i <= sz; i++) {
                    nxrt[i] = sgt[tsrt[i]].r;
                }
                return query(rt + 1, sz, m + 1, r, k);
            }
        } else {
            for (int i = 1; i <= sz; i++) {
                nxrt[i] = sgt[tsrt[i]].l;
            }
            return query(rt + 1, sz, l, m, k);
        }
    }
    int m = (l + r) >> 1;
    if (k > m) {
        for (int i = 1; i <= sz; i++) {
            nxrt[i] = sgt[tsrt[i]].r;
        }
        return query(rt + 1, sz, m + 1, r, k);
    } else {
        for (int i = 1; i <= sz; i++) {
            nxrt[i] = sgt[tsrt[i]].l;
        }
        int t = query(rt + 1, sz, l, m, k);

        // printf("%d\n",t);

        if (t == -1) {
            for (int i = 1; i <= sz; i++) {
                nxrt[i] = sgt[tsrt[i]].r;
            }
            return query(rt + 1, sz, m + 1, r, k);
        } else {
            return t;
        }
    }
}

int a[100050];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int q, sz;
        scanf("%d%d", &n, &q);
        init();
        memset(root, 0, sizeof(root[0]) * (n + 2));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sz = extract(i);
            for (int j = 1; j <= sz; j++) {
                update(root[rts[0][j]], 1, n + 1, a[i], 1);
            }
        }
        int o, pos, r, k, lastans = 0;
        for (int i = 1; i <= q; i++) {
            scanf("%d", &o);
            if (o == 1) {
                scanf("%d", &pos);
                pos = lastans ^ pos;
                if (a[pos] == -1) {
                    continue;
                } else {
                    sz = extract(pos);
                    for (int j = 1; j <= sz; j++) {
                        update(root[rts[0][j]], 1, n + 1, a[pos], -1);
                    }
                    a[pos] = -1;
                }
            } else {
                scanf("%d", &r);
                scanf("%d", &k);

                r = lastans ^ r;
                k = lastans ^ k;

                // print f("![%d %d]\n",r, k);

                sz = extracts(r);

                for (int i = 1; i <= sz; i++) {
                    rts[0][i] = root[rts[0][i]];
                }

                printf("%d\n", lastans = query(rts, sz, 1, n + 1, k));
            }
        }
    }
}