#include <cstdio>
#include <utility>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int,int>;


vector<pii> rnk;


pair<pii, int> task[100060];
#define lowbit(x) ((x)&(-(x)))
int b[100050],n;

void add(int x, int t) {
    while(x<=n) {
        b[x]+=t;
        // printf("%d %d %d\n",n, x, lowbit(x));
        x+=lowbit(x);
    }
}

int sum(int x) {
    int ret=0;
    while(x) {
        ret+=b[x];
        x-=lowbit(x);
    }
    return ret;
}

// struct ss {
//     int s;int id;
// }s[100500];

pii s[100050];
int ret[100050];
int main() {
    int q;
    scanf("%d%d",&n,&q);

    for(int i=1;i<=n;i++) {
        scanf("%d",&s[i].first);
        s[i].second = i;
    }
    sort(s+1,s+1+n);
    for(int i=1;i<=n;i++) {
        for(int j=i+i;j<=n;j+=i) {
            auto p = (pii){s[i].second, s[j].second};
            if(p.first > p.second) {
                swap(p.first, p.second);
            }
            rnk.push_back(p);
        }
    }
    sort(rnk.begin(),rnk.end());

    
    // for (auto &p : rnk) {
    //     printf("[%d %d]", p.first, p.second);
    // }
    // return 0;

    for(int i=1;i<=q;i++) {
        scanf("%d",&task[i].first.first);
        scanf("%d",&task[i].first.second);
        task[i].second = i;
    }
    sort(task+1,task+1+q);


    int pi = 0;
    for (auto &p : rnk) {
        add(p.second, 1);
        // printf("...");
    }
    for(int i=1;i<=q;i++) {
        while(pi<rnk.size() && rnk[pi].first < task[i].first.first) {
            add(rnk[pi].second,-1);
            pi++;
        }
        ret[task[i].second] = sum(task[i].first.second);
    }
    for(int i=1;i<=q;i++) {
        printf("%d\n",ret[i]);
    }
}

/*
4 10
2 1 3 4
1 1
1 2
1 3
1 4
2 2
2 3
2 4
3 3
3 4
4 4

*/