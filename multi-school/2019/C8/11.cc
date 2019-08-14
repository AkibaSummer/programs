#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;


struct P {
    int a,b;
} e[1000050];

// int a[1000050],b[1000050];

bool cmp(P &a, P &b) {
    return (a.b == b.b && a.a < b.a) || (a.b > b.b);
}

queue<pair<int,int> > Q;
int main() {
    int n;
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d%d",&e[i].a, &e[i].b);
        }

        sort(e+1,e+1+n,cmp);

        long long ret = 0; 

        while(Q.size())Q.pop();

        for(int i=1;i<=n;i++) {
            Q.push({i, e[i].b});
        }

        pair<int,int > t1, t2;
        for(int i=1;i<=n;i++) {
            t1 = {-1, 0};
            while(e[i].a && Q.size()) {
                t2 = Q.front(); Q.pop();
                if(t2.first == i) {
                    t1 = t2;
                    continue;
                }

                // printf("%d %d %d\n", i, t2.first, t2.second);
                if(e[i].a>= t2.second) {
                    ret+=t2.second;
                    e[i].a-=t2.second;
                } else {
                    ret+=e[i].a;
                    Q.push({t2.first, t2.second-e[i].a});
                    e[i].a = 0;
                }
            }
            // printf("%d\n",e[i].a);
            if(t1.first != -1) {
                // puts("233");
                Q.push(t1);
            }
        }
        
        printf("%lld\n",ret);

    }
}
/*
1
3
4 1
3 4
3 3
*/