#include <cstdio>
#include <algorithm>
#include <set>
#include <cstdlib>
using namespace std;

struct ss {
    long long a,b;
} x[100050];

bool cmpa(ss &a, ss &b) {
    return a.a < b.a;
}
long long mxb[100050];


set<long long> s;
int main() {
    int n;

    int T;
    scanf("%d",&T);
    while(T--) {
        s.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%lld%lld",&x[i].a,&x[i].b);
        }
        sort(x+1,x+1+n,cmpa);
        mxb[n+1]=0;
        for(int i=n;i>=1;i--) {
            mxb[i] = max(x[i].b, mxb[i+1]);
        }

        // for(int i=1;i<=n;i++) {
        //     printf("%lld %lld %lld\n", x[i].a, x[i].b, mxb[i]);
        // }

        long long ret = 0x3f3f3f3f3f3f3f3fLL;
        for(int i=1;i<n;i++) {
            if(mxb[i+1] > x[i].a) {
                ret = min(mxb[i+1]-x[i].a,ret);
            } else {
                if(s.size()) {
                    auto q = s.upper_bound(x[i].a);
                    if(q == s.begin()) {
                        ret = min(min(abs(*q-x[i].a), abs(mxb[i+1]-x[i].a)), ret);
                    } else {
                        if(q!=s.end())ret = min(min(abs(*q-x[i].a), abs(mxb[i+1]-x[i].a)), ret);
                        q--;
                        ret = min(min(abs(*q-x[i].a), abs(mxb[i+1]-x[i].a)), ret);
                    }
                } else {
                    ret = min(x[i].a-mxb[i+1],ret);
                }
            }
            s.insert(x[i].b);
        }
        auto q = s.upper_bound(x[n].a);
        if(q == s.end()) {
            q--;
            ret = min (ret ,abs(*q - x[n].a));
        } else {
            ret = min (ret ,abs(*q - x[n].a));
            if(q != s.begin()) {
                q--;
                ret = min (ret ,abs(*q - x[n].a));
            }
        }

        printf("%lld\n", ret);
    }
}