#include <cstdio>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int,int>;


vector<pii> rnk;

map<pii, int> ret;
map<pii, bool> exists;
int main() {
    int n;
    scanf("%d",&n);
    rnk.reserve(n);
    auto p = (pii){1,1};
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&p.first, &p.second);
        rnk.push_back(p);
    }

    sort(rnk.begin(), rnk.end());
    rnk.erase(unique(rnk.begin(), rnk.end()), rnk.end());

    if(rnk.size()==1){
        puts("0");
        return 0;
    }


    for(auto &c:rnk) {
        exists[c]=true;
    }
    for(int i=0;i<rnk.size();i++) {
        for(int j=i+1;j<rnk.size();j++) {
            ret[{rnk[i].first + rnk[j].first, rnk[i].second + rnk[j].second}]++;
        }
    }
    int res = rnk.size();

    for(auto &tmp:ret) {
        if((tmp.first.first & 1) || (tmp.first.second & 1) ) {
            res = min((int)rnk.size()-tmp.second*2, res);
        } else {
            res = min((int)rnk.size()-exists[{tmp.first.first>>1, tmp.first.second>>1}]-tmp.second*2, res);
        }
        
    }

    printf("%d\n",res);


}