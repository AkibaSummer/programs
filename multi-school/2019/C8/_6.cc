#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[2][100500];
long long dp[2][100500];
pair<long long, int> mx[2][100500];
pair<long long, int> smax[2][100500];

struct edge
{
    int nx, to;
} e[200050];

int head[100050], mal = 1;
void init(int n)
{
    memset(head, 0, sizeof(int) * (n + 2));
    mal = 1;
}

void addedge(int u, int v)
{
    e[mal].to = v;
    e[mal].nx = head[u];
    head[u] = mal++;
}

void addedges(int u, int v)
{
    addedge(u, v);
    addedge(v, u);
}

const long long LMAX = 1ll << 60ll, LMIN = -1ll << 60ll;
void dfs1(int u, int f)
{

    dp[0][u] = a[0][u] - a[1][u];
    dp[1][u] = a[1][u] - a[0][u];

    mx[0][u] = {LMIN, -1};
    mx[1][u] = {LMIN, -1};

    smax[0][u] = {LMIN, -1};
    smax[1][u] = {LMIN, -1};

    for (int i = head[u]; i; i = e[i].nx)
    {
        int v = e[i].to;
        if (v == f)
        {
            continue;
        }

        dfs1(v, u);

        if (smax[0][u].first < dp[0][v])
        {
            smax[0][u].first = dp[0][v];
            smax[0][u].second = v;
        }

        if (mx[0][u].first < smax[0][u].first)
        {
            swap(mx[0][u], smax[0][u]);
        }

        if (smax[1][u].first < dp[1][v])
        {
            smax[1][u].first = dp[1][v];
            smax[1][u].second = v;
        }

        if (mx[1][u].first < smax[1][u].first)
        {
            swap(mx[1][u], smax[1][u]);
        }
    }
    // printf("dp:%d %lld %lld %d %d\n",u,dp[0][u], dp[1][u],a[0][u], a[1][u]);

    if (mx[0][u].first != LMIN) {
        dp[1][u] = -mx[0][u].first + dp[1][u];
    }
    if (mx[1][u].first != LMIN) {
        dp[0][u] = -mx[1][u].first + dp[0][u];
    }

    // printf("dp:%d %lld %lld\n",u,dp[0][u], dp[1][u]);
    // printf("mx:%d (%lld, %d) (%lld, %d)\n",u,mx[0][u].first, mx[0][u].second, mx[1][u].first, mx[1][u].second );
    // printf("smax:%d (%lld, %d) (%lld, %d)\n",u,smax[0][u].first, smax[0][u].second, smax[1][u].first, smax[1][u].second);

}

void dfs2(int u, int f) {
    if(u!=1) {
        auto fmx = mx[0][f];
        long long fadp = LMAX;
        // printf("ddp:%d %lld %lld\n",u,dp[0][u], dp[1][u]);
        if(fmx.first == u && smax[0][f].second != -1) {
            fadp = -smax[0][f].first + a[1][f] - a[0][f];
        }  {
            fadp = -mx[0][f].first + a[1][f] - a[0][f];
        }
        dp[1][u] = min(fadp + a[1][u] - a[0][u], dp[1][u]);
        
        if (fadp == LMAX) {
            fadp = LMIN;
        }

        if (smax[0][u].first < fadp)
        {
            smax[0][u].first = fadp;
            smax[0][u].second = f;
        }

        if (mx[0][u].first < smax[0][u].first)
        {
            swap(mx[0][u], smax[0][u]);
        }

        fmx = mx[1][f];
        fadp = LMAX;
        if(fmx.first == u && smax[1][f].second != -1) {
            fadp = -smax[1][f].first + a[0][f] - a[1][f];
        } else {
            fadp = -mx[1][f].first + a[0][f] - a[1][f];
        }
        dp[0][u] = min(fadp + a[0][u] - a[1][u], dp[0][u]);


        if (fadp == LMAX) {
            fadp = LMIN;
        }

        if (smax[1][u].first < fadp)
        {
            smax[1][u].first = fadp;
            smax[1][u].second = f;
        }

        if (mx[1][u].first < smax[1][u].first)
        {
            swap(mx[1][u], smax[1][u]);
        }

        
        // printf("ddp:%d %lld %lld\n",u,dp[0][u], dp[1][u]);
        // printf("mx:%d (%lld, %d) (%lld, %d)\n",u,mx[0][u].first, mx[0][u].second, mx[1][u].first, mx[1][u].second );
        // printf("smax:%d (%lld, %d) (%lld, %d)\n",u,smax[0][u].first, smax[0][u].second, smax[1][u].first, smax[1][u].second);
    }
    for (int i = head[u]; i; i = e[i].nx)
    {
        int v = e[i].to;
        if (v == f)
        {
            continue;
        }

        dfs2(v, u);
    }
}

int main() 
{

    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        init(n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[0][i]);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d",  &a[1][i]);
        }

        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addedges(u, v);
        }

        dfs1(1, 0);
        dfs2(1, 0);

        long long ret = LMIN;
        for(int i=1;i<=n;i++) {
            ret = max(ret, dp[0][i]);
        }
        printf("%lld\n",ret);
    }
}