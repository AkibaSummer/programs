#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
#define int long long
int A[maxn];
struct node {
    long long val, Lazy;
    int l, r;
} Tree[1000100];
void build(int Root, int l, int r) {
    Tree[Root].l = l;
    Tree[Root].r = r;
    Tree[Root].val = Tree[Root].Lazy = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build((Root << 1) + 1, l, mid);
    build((Root << 1) + 2, mid + 1, r);
}
void push_down(int Root) {
    int tmp = Root << 1;
    if (Tree[Root].Lazy) {
        Tree[tmp + 1].val += Tree[Root].Lazy;
        Tree[tmp + 2].val += Tree[Root].Lazy;
        Tree[tmp + 1].Lazy += Tree[Root].Lazy;
        Tree[tmp + 2].Lazy += Tree[Root].Lazy;
        Tree[Root].Lazy = 0;
    }
}
void push_up(int Root) {
    int tmp = Root << 1;
    Tree[Root].val = min(Tree[tmp + 1].val, Tree[tmp + 2].val);
}
void change(int Root, int l, int r, long long val = 10000000000005ll) {
    int op = Tree[Root].l;
    int ed = Tree[Root].r;
    if (op > ed)
        return;
    push_down(Root);
    if (op == l && ed == r) {
        Tree[Root].val += val;
        Tree[Root].Lazy += val;
        return;
    }
    int mid = (op + ed) >> 1;
    int tmp = Root << 1;
    if (r <= mid)
        change(tmp + 1, l, r, val);
    else if (l > mid)
        change(tmp + 2, l, r, val);
    else {
        change(tmp + 1, l, mid, val);
        change(tmp + 2, mid + 1, r, val);
    }
    push_up(Root);
}
long long sum(int Root, int l, int r) {
    int op = Tree[Root].l;
    int ed = Tree[Root].r;
    if (op > ed)
        return 0;
    push_down(Root);
    if (op == l && ed == r)
        return Tree[Root].val;
    int mid = (op + ed) >> 1;
    if (r <= mid)
        return sum(Root * 2 + 1, l, r);
    else if (l > mid)
        return sum(Root * 2 + 2, l, r);
    return min(sum(Root * 2 + 1, l, mid), sum(Root * 2 + 2, mid + 1, r));
}
int n;
int getans() {
    int L = 1, R = n + 1, ans = 0;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (sum(0, mid, R) > 0) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    return ans;
}
long long a[maxn];
signed main() {
    //    cin>>n;
    int pos;
    scanf("%lld", &n);
    build(0, 1, n + 1);
    change(0, n + 1, n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", A + i);
    }
    for (int i = 1; i <= n; i++) {
        change(0, i, i, A[i]);
    }
    for (int i = 1; i <= n; i++) {
        pos = getans() - 1;
        a[pos] = i;
        change(0, pos, pos);
        change(0, pos + 1, n + 1, -i);
    }
    for (int i = 1; i <= n; i++)
        printf("%lld ", a[i]);
    return 0;
}