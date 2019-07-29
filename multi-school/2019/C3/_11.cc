#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const long long maxn=2000005;

struct link{
    long long target,weight;
};

struct que_node{
    long long dis1,id;
    bool operator < (const que_node &r)const{
        return dis1==r.dis1?id>r.id:dis1>r.dis1;
    }
};

struct dp_node{
    long long dis1,dis0;
};

struct edge {
    long long nx,w,to;
}e[maxn * 2];

long long head[maxn], mal;
void init(long long n) {
    memset(head,0,sizeof(long long)*(n+1));
    mal = 1;
}
void addedge(long long u, long long v, long long w) {
    e[mal].to = v; e[mal].w = w; e[mal].nx = head[u]; head[u] = mal ++;
}

void addedges(long long u, long long v, long long w) {
    addedge(u,v,w);
    addedge(v,u,w);
}



// vector<link> links[maxn];
long long deg[maxn];
long long vis[maxn];
dp_node dp[maxn];

void slove(){
    long long n;
    scanf("%lld",&n);
    init(n);
    for (long long i=1;i<=n;i++){
        deg[i]=0;
        vis[i]=0;
        // links[i].clear();
        dp[i]={0,0};
    }
    for (long long i=1;i<n;i++){
        long long q,w,e;
        scanf("%lld%lld%lld",&q,&w,&e);
        deg[q]++;
        deg[w]++;
        addedges(q,w,e);
        // links[q].push_back({w,e});
        // links[w].push_back({q,e});
    }
    long long num=n;
    priority_queue<que_node> que;
    for (long long i=1;i<=n;i++){
        if (deg[i]==1){
            vis[i]=1;
            que.push({0,i});
            num--;
        }
    }
    que_node temp;
    while (num!=0){
        temp=que.top();
        que.pop();
        for(long long ii = head[temp.id]; ii ; ii = e[ii].nx) {
            long long v = e[ii].to, w = e[ii].w;
            link i={v,w};
            if (!vis[i.target]){
                deg[i.target]--;
                dp[i.target].dis0=max(dp[i.target].dis0,dp[temp.id].dis0+i.weight);
                dp[i.target].dis1=max(dp[i.target].dis1,min(dp[temp.id].dis0,dp[temp.id].dis1+i.weight));
                if (deg[i.target]==1){
                    vis[i.target]=1;
                    que.push({dp[i.target].dis1,i.target});
                    num--;
                }
            }
        }
        // for (auto &i:links[temp.id]){
        //     if (!vis[i.target]){
        //         deg[i.target]--;
        //         dp[i.target].dis0=max(dp[i.target].dis0,dp[temp.id].dis0+i.weight);
        //         dp[i.target].dis1=max(dp[i.target].dis1,min(dp[temp.id].dis0,dp[temp.id].dis1+i.weight));
        //         if (deg[i.target]==1){
        //             vis[i.target]=1;
        //             que.push({dp[i.target].dis1,i.target});
        //             num--;
        //         }
        //     }
        // }
    }
    // cout<<que.size()<<endl;
    long long node1=que.top().id;
    que.pop();
    long long node2=que.top().id;
    long long distance;
    for(long long i = head[node1]; i ; i = e[i].nx) {
        long long v = e[i].to, w = e[i].w;
        if (v==node2){
            distance=w;
            break;
        }
    }
    // for (auto &i:links[node1]){
    //     if (i.target==node2){
    //         distance=i.weight;
    //         break;
    //     }
    // }
    long long ans = 1<<30,node;
    if (max(dp[node1].dis0,dp[node2].dis0)<=ans){
        ans = max(dp[node1].dis0,dp[node2].dis0);
        node = min(node1,node2);
    }
    if (max(dp[node1].dis0,dp[node2].dis1+distance)<=ans){
        ans = max(dp[node1].dis0,dp[node2].dis1+distance);
        node = node1;
    }
    if (max(dp[node2].dis0,dp[node1].dis1+distance)<=ans){
        ans = max(dp[node2].dis0,dp[node1].dis1+distance);
        node = node2;
    }
    printf("%lld %lld\n",node,ans);
    // cout<<node<<' '<<ans<<endl;
    // for (long long i=1;i<=n;i++){
    //     cout<<dp[i].dis0<<' '<<dp[i].dis1<<endl;
    // }
}

int main(){
    long long t;
    scanf("%lld",&t);
    while (t--){
        slove();
    }
}