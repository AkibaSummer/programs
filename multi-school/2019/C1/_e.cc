#include <bits/stdc++.h>

using namespace std;

const long long INF = 1ll << 62;
const long long maxn = 10005;

    long long n, m;

struct link
{
    long long target, weight;
    bool operator<(const link &r) const
    {
        return weight > r.weight;
    }
};

vector<link> links[maxn];
long long mindist[maxn];
long long vist[maxn];

void getmindist(long long n)
{
    mindist[1] = 0;
    priority_queue<link> que;
    que.push({1, 0});
    link temp;
    while (!que.empty())
    {
        temp = que.top();
        que.pop();
        long long u = temp.target;
        if (vist[u])
            continue;
        vist[u] = true;
        for (auto &i : links[u])
        {
            long long v = i.target;
            long long cost = i.weight;
            if (!vist[v] && mindist[v] > mindist[u] + cost)
            {
                mindist[v] = mindist[u] + cost;
                que.push({v, mindist[v]});
            }
        }
    }
}

// struct Edge{
//     long long to,next,cap,flow,cost;
// }edge[maxn];
// long long head[maxn],tol;
// long long pre[maxn],dis[maxn];
// bool vis[maxn];
// long long N;
// void init(long long n){
//     N=n;
//     tol=0;
//     memset(head,-1,sizeof(head));
// }
// void addedge(long long u,long long v,long long cap,long long cost){
//     edge[tol].to = v;
//     edge[tol].cap = cap;
//     edge[tol].cost = cost;
//     edge[tol].flow = 0;
//     edge[tol].next = head[u];
//     head[u] = tol++;
//     // edge[tol].to = u;
//     // edge[tol].cap = 0;
//     // edge[tol].cost = -cost;
//     // edge[tol].flow = 0;
//     // edge[tol].next = head[v];
//     // head[v] = tol++;
// }

// bool spfa(long long s,long long t){
//     queue<int>q;
//     for(long long i = 0;i < N;i++){
//         dis[i] = INF;
//         vis[i] = false;
//         pre[i] = -1;
//     }
//     dis[s] = 0;
//     vis[s] = true;
//     q.push(s);
//     while(!q.empty()){
//         long long u = q.front();
//         q.pop();
//         vis[u] = false;
//         for(long long i = head[u]; i != -1;i = edge[i].next){
//             long long v = edge[i].to;
//             if(edge[i].cap > edge[i].flow && dis[v] > dis[u] + edge[i].cost ){
//                 dis[v] = dis[u] + edge[i].cost;
//                 pre[v] = i;
//                 if(!vis[v]){
//                     vis[v] = true;
//                     q.push(v);
//                 }
//             }
//         }
//     }
//     if(pre[t] == -1)return false;
//     else return true;
// }

// long long minCostMaxflow(long long s,long long t,long long &cost){
//     long long flow = 0;
//     cost = 0;
//     while(spfa(s,t)){
//         long long Min = INF;
//         for(long long i = pre[t];i != -1;i = pre[edge[i^1].to]){
//                 if(Min > edge[i].cap - edge[i].flow)
//                     Min = edge[i].cap - edge[i].flow;
//             }
//             for(long long i = pre[t];i != -1;i = pre[edge[i^1].to]){
//                 edge[i].flow += Min;
//                 edge[i^1].flow -= Min;
//                 cost += edge[i].cost * Min;
//         }
//         flow += Min;
//     }
//     return flow;
// }

// struct Edge
// {
//     long long to, next, cap, flow;
// } edge[maxn];
// long long tol;
// long long head[maxn];
// void init()
// {
//     tol = 2;
//     memset(head, -1, sizeof(head));
// }
// void addedge(long long u, long long v, long long w, long long rw = 0)
// {
//     edge[tol].to = v;
//     edge[tol].cap = w;
//     edge[tol].flow = 0;
//     edge[tol].next = head[u];
//     head[u] = tol++;
//     // edge[tol].to = u;
//     // edge[tol].cap = rw;
//     // edge[tol].flow = 0;
//     // edge[tol].next = head[v];
//     // head[v] = tol++;
// }
// long long Q[maxn];
// long long dep[maxn], cur[maxn], sta[maxn];
// bool bfs(long long s, long long t, long long n)
// {
//     long long front = 0, tail = 0;
//     memset(dep, -1, sizeof(dep[0]) * (n + 1));
//     dep[s] = 0;
//     Q[tail++] = s;
//     while (front < tail)
//     {
//         long long u = Q[front++];
//         for (long long i = head[u]; i != -1; i = edge[i].next)
//         {
//             long long v = edge[i].to;
//             if (edge[i].cap > edge[i].flow && dep[v] == -1)
//             {
//                 dep[v] = dep[u] + 1;
//                 if (v == t)
//                     return true;
//                 Q[tail++] = v;
//             }
//         }
//     }
//     return false;
// }
// long long dinic(long long s, long long t, long long n)
// {
//     long long maxflow = 0;
//     while (bfs(s, t, n))
//     {
//         for (long long i = 0; i < n; i++)
//             cur[i] = head[i];
//         long long u = s, tail = 0;
//         while (cur[s] != -1)
//         {
//             if (u == t)
//             {
//                 long long tp = INF;
//                 for (long long i = tail - 1; i >= 0; i--)
//                     tp = min(tp, edge[sta[i]].cap - edge[sta[i]].flow);
//                 maxflow += tp;
//                 for (long long i = tail - 1; i >= 0; i--)
//                 {
//                     edge[sta[i]].flow += tp;
//                     edge[sta[i] ^ 1].flow -= tp;
//                     if (edge[sta[i]].cap - edge[sta[i]].flow == 0)
//                         tail = i;
//                 }
//                 u = edge[sta[tail] ^ 1].to;
//             }
//             else if (cur[u] != -1 && edge[cur[u]].cap > edge[cur[u]].flow && dep[u] + 1 == dep[edge[cur[u]].to])
//             {
//                 sta[tail++] = cur[u];
//                 u = edge[cur[u]].to;
//             }
//             else
//             {
//                 while (u != s && cur[u] == -1)
//                     u = edge[sta[--tail] ^ 1].to;
//                 cur[u] = edge[cur[u]].next;
//             }
//         }
//     }
//     return maxflow;
// }

struct edge
{
    long long to, cap, rev;
};
vector<edge> G[maxn];
long long level[maxn], iter[maxn];
void addedge(long long from, long long to, long long cap)
{
    G[from].push_back(edge{to, cap, (int)G[to].size()});
    G[to].push_back(edge{from, 0, (int)G[from].size() - 1}); //反向容量为0!!
}
void bfs(long long s)
{
    memset(level, -1, sizeof(long long)*(n+1));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty())
    {
        long long t = que.front();
        que.pop();
        for (long long i = 0; i < G[t].size(); i++)
        {
            edge e = G[t][i];
            if (e.cap > 0 && level[e.to] < 0)
            {
                level[e.to] = level[t] + 1;
                que.push(e.to);
            }
        }
    }
}
long long dfs(long long v, long long t, long long f)
{
    if (v == t)
        return f;
    for (long long &i = iter[v]; i < G[v].size(); i++)
    { //注意传引用!
        edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to])
        {
            long long d = dfs(e.to, t, min(f, e.cap));
            if (d > 0)
            {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0; //不要漏了这个,很多时候可能是无法增广的
}
long long maxflow(long long s, long long t)
{
    long long flow = 0; //小心爆int
    for (;;)
    {
        bfs(s);
        if (level[t] < 0)
            return flow;
        memset(iter, 0, sizeof(long long)*(n+1));
        long long f;
        while (f = dfs(s, t, INF)) //注意如果爆int这里初始最大值要更改最大值
            flow += f;
    }
}

void getminlinks(long long n)
{
    for (long long i = 1; i <= n; i++)
    {
        for (auto &j : links[i])
        {
            if (abs(mindist[i] - mindist[j.target]) == j.weight)
                addedge(i, j.target, j.weight);
        }
    }
}

void slove()
{
    scanf("%lld%lld", &n, &m);

    for (long long i = 1; i <= n; i++)
    {
        links[i].clear();
        mindist[i] = INF;
        vist[i] = 0;
    }

    for (long long i = 1; i <= m; i++)
    {
        long long x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        links[x].push_back({y, z});
        // links[y].push_back({x, z});
    }
    getmindist(n);
    if (mindist[n]==INF){
        printf("0\n");
        return ;
    }
    getminlinks(n);
    // long long cost = 0;
    printf("%lld\n", maxflow(1, n));
}

int main()
{
    long long t;
    scanf("%lld", &t);
    while (t--)
    {
        slove();
    }
}