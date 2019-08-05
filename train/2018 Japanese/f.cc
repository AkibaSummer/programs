#include <bits/stdc++.h>
using namespace std;
const long long maxn = 200000 + 10;

long long flagg[100050];

struct tarjan
{ //tarjan模板
    long long n;
    vector<pair<long long, long long>> e[maxn]; //边集
    long long dfn[maxn];                        //dfn数组是个时间戳，就是访问那个节点的时间，也就是第几次调用dfs这个函数
    long long low[maxn];                        //Low是u的子节点能通过反向边到达的节点DFN的最小值, 初始值为dfn[u]
    long long index;                            //记录dfs调用的次数
    long long edge[maxn];                       //记录割边
    long long node[maxn];                       //记录割点
    long long f[maxn];                          //父亲节点
    long long s[maxn];                          //儿子节点的个数
    long long cnt_edge;                         //割边的边数
    long long cnt_node;                         //割点的点数
    void init(long long N)
    { //初始化
        n = N;
        for (long long i = 1; i <= n; i++)
            e[i].clear();
        index = 0;
        cnt_node = 0;
        cnt_edge = 0;
        memset(dfn, -1, sizeof(dfn));
        memset(f, 0, sizeof(f));
        memset(s, 0, sizeof(s));
    }
    void addedge(long long u, long long v, long long id)
    { //添加边
        e[u].push_back({v, id});
    }
    void dfs(long long u)
    { //dfs类似环缩点的写法，两个主要数组dfn[]和low[]
        dfn[u] = low[u] = ++index;
        bool flag = 0;
        for (long long i = 0; i < e[u].size(); i++)
        {
            long long &v = e[u][i].first;
            if (dfn[v] == -1)
            {
                s[u]++;
                f[v] = u;
                dfs(v);
                if (low[v] >= dfn[u])
                {
                    flag = 1;
                }
                if (low[v] > dfn[u])
                { //low[v]大于dfn[u]表示除原路径外，没有其他路径使得v回到u，即无法形成环，所以是割边
                    flagg[e[u][i].second] = 1;
                }
                low[u] = min(low[u], low[v]);
            }
            else if (v != f[u])
                low[u] = min(low[u], dfn[v]);
        }
        if ((f[u] == 0 && s[u] >= 2) || (f[u] && flag)) // 1.该点为dfs树的根结点，若这个根节点有两颗及以上的子树，则为割点
            node[cnt_node++] = u;                       //2.该点不是dfs树的根结点，若存在v为u的子节点且low[v]>=dfn[u]的话，则也是一个割点
    }
    void solve()
    { //遍历所有点
        for (long long i = 1; i <= n; i++)
        {
            if (dfn[i] == -1)
                dfs(i);
        }
    }

} T;

// long long main() {
// 	T.init(n);
// 	for(long long i=1; i<=m; i++) {
// 		scanf("%lld %lld",&u,&v);
// 		T.addedge(u,v);
// 		T.addedge(v,u);
// 	}
// 	T.solve();

// 	return 0;
// }

long long diss[100050], dist[100050];
bool vis[100050];

struct edge
{
    long long to, nx, w;
} e[200050];

long long head[100050], mal = 1;
void init()
{
    mal = 1;
    memset(head, 0, sizeof(head));
}
long long u[200050], v[200050], w[200050];
void addedge(long long uu, long long vv, long long ww)
{
    e[mal].to = vv;
    e[mal].w = ww;
    e[mal].nx = head[uu];
    head[uu] = mal++;
}

struct node
{
    long long v;
    long long dis;
    bool operator<(const node &y) const
    {
        return dis > y.dis;
    }
};
void dijk(long long dis[], long long s)
{
    static priority_queue<node> Q;
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x01, sizeof(long long) * 100005);
    node tmp;
    Q.push(node{s, dis[s] = 0});
    while (Q.size())
    {
        tmp = Q.top();
        Q.pop();
        // cout<<tmp.v<<endl;
        if (vis[tmp.v])
            continue;
        vis[tmp.v] = 1;
        for (long long i = head[tmp.v]; i; i = e[i].nx)
        {
            long long v = e[i].to;
            if (e[i].w + dis[tmp.v] < dis[v])
            {
                dis[v] = e[i].w + dis[tmp.v];
                Q.push(node{v, dis[v]});
            }
        }
    }
}
vector<long long> edges;
void solve(long long m, vector<long long> &ret)
{
    ret.clear();

    for (long long i = 1; i <= m; i++)
    {
        if (diss[u[i]] + w[i] + dist[v[i]] == diss[2])
        {
            ret.push_back(i);
        }
    }
}

signed main()
{

    long long n, m, s = 1, t = 2;
    scanf("%lld%lld", &n, &m);
    for (long long i = 1; i <= m; i++)
    {
        long long uu, vv, ww;
        scanf("%lld%lld%lld", &uu, &vv, &ww);
        u[i] = uu;
        v[i] = vv;
        w[i] = ww;
        addedge(uu, vv, ww);
    }
    // puts("st dijks");
    dijk(diss, s);
    // for (long long i=1;i<=n;i++){
    //     cout<<diss[i]<<" ";
    // }
    // puts("");
    init();
    for (long long i = 1; i <= m; i++)
    {
        addedge(v[i], u[i], w[i]);
    }
    // puts("st dijkt");
    dijk(dist, t);
    // for (long long i=1;i<=n;i++){
    //     cout<<dist[i]<<" ";
    // }
    // puts("");

    // puts("st slove");
    solve(m, edges);
    // puts("ed slove");
    T.init(n);

    // puts("1");
    // for (auto i:edges){
    //     cout<<i<<' ';
    // }
    // puts("2");

    for (auto i : edges)
    {
        T.addedge(u[i], v[i], i);
    }
    T.solve();

    // puts("");
    // for (long long i=1;i<=n;i++){
    //     if (flagg[i])cout<<i<<' ';
    // }
    // puts("");

    for (long long i = 1; i <= m; i++)
    {
        if (flagg[i])
        {
            if (diss[v[i]] + dist[u[i]] + w[i] < diss[t])
            {
                puts("HAPPY");
            }
            else if (diss[v[i]] + dist[u[i]] + w[i] == diss[t])
            {
                puts("SOSO");
            }
            else
                puts("SAD");
        }
        else
        {
            if (diss[v[i]] + dist[u[i]] + w[i] < diss[t])
            {
                puts("HAPPY");
            }
            else
                puts("SOSO");
        }
    }
}