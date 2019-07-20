#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

struct link {
	long long target, weiget;
};
vector<link> links[100005];
long long ans[100005];
long long vist[100005];

void del(long long now){
    vist[now]=1;
    for (auto &i:links[now]){
        if (!vist[i.target]&&links[i.target].size()==2){
            del(i.target);
        }
    }
}

long long target = 0;

long long sumx=0,sum=0;

void find(long long now,long long pre,long long flag){
    for (auto &i:links[now]){
        if (i.target==pre)continue;
        else if (vist[i.target]==1)continue;
        else if (i.target==target){
            sum+=i.weiget;
            ans[i.target]=sum/2-sumx;
            // cout<<sum<<" "<<sumx<<endl;
            return ;
        }
        else if (vist[i.target]==0){
            vist[i.target]=2;
            if (flag)sumx+=i.weiget;
            sum+=i.weiget;
            find(i.target,now,1-flag);
            return ;
        }
    }
} 

void setans(long long now){
    for (auto &i:links[now]){
        if (vist[i.target]!=3){
            vist[i.target]=3;
            ans[i.target]=i.weiget-ans[now];
            setans(i.target);
        }
    }
}

int main() {
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		long long q, w, e;
		cin >> q >> w >> e;
		links[q].push_back({ w,e });
		links[w].push_back({ q,e });
	}
    for (long long i=1;i<=n;i++){
        if (links[i].size()==1)del(i);
    }
    for (long long i=1;i<=n;i++){
        if (!vist[i]) {
            target = i;
            vist[target]=2;
            find(i,0,0);
        }
    }
    vist[target]=3;
    setans(target);
    for (long long i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
}