#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
// struct edge {
//     int to, nx;
// }e[500005];


// int head[500050], mal =1;

// void addedge(int u, int v) {
//     e[mal].to = v; e[mal].nx = head[u]; head[u] = mal++;
// }

vector<int> G[500050];

void addedge(int u, int v) {
    G[u].push_back(v);
}

struct topic {
    int t,id;
    bool operator<(const topic &b) const {
        return t>b.t;
    }
} x[500050];

bool cmp2(topic &x, topic &y) {
    return x.t > y.t;
}

int s[500050];
bool taolunguo[500050],vis[500050];
int  mx[500050];
int ret =0, curtopic = 0;

int findmax(int u) {
    if(vis[u])return mx[u];
    mx[u] = s[u];
    vis[u]=1;
    for(auto preq:G[u]) {
        mx[u] = max(mx[u], findmax(preq));
    }
    return mx[u];
}

bool cmp(int x, int y) {
    return mx[x] > mx[y];
}

void taolun(int u) {
    if(taolunguo[u])return;
    sort(G[u].begin(),G[u].end(),cmp);
    for(auto preq:G[u]) {
        taolun(preq);
    }
    taolunguo[u] = 1;
    ret = max(ret, curtopic+s[u]);
    // printf("taolun %d %d\n", u , curtopic+s[u]);
    curtopic++;
}

int main() {
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++) {
        int d;
        scanf("%d%d",&s[i],&d);
        x[i].t = s[i];x[i].id=i;
        for(int j=1;j<=d;j++) {
            int preq;
            scanf("%d",&preq);
            addedge(i, preq);
            // deg[i]++;
        }
    }
    sort(x+1,x+1+n,cmp2);

    for(int i=1;i<=n;i++) {
        findmax(i);
    }


    for(int i=1;i<=n;i++) {
        taolun(x[i].id);
    }


    // for(int i=1;i<=n;i++) {
    //     if(deg[i]==0) {
    //         Q.push(s[i]);
    //     }
    // }

    // while(Q.size()) {
    //     auto tpc = Q.top();Q.pop();
    //     ret = max(tpc.t + curtopic, ret);
    //     curtopic++;
    //     for(int i = head[tpc.id];i;i=e[i].nx) {
    //         int v= e[i].to;
    //         if(--deg[v]==0) {
    //             Q.push(s[v]);
    //         }
    //     }
    // }
    printf("%d\n",ret);
}

/*
3
10 0
10 0
10 0

6
2 2 4 3
4 1 5
1 2 2 4
3 1 5
2 0
4 1 3


9
1 0
101 1 1
1 1 1
1 1 1
2 2 2 3
1 1 3
100 1 4
100 1 6
100 2 5 6
*/