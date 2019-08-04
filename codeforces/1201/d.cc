#include <bits/stdc++.h>
using namespace std;

const long long inf = 1ll<<60;

long long pre(long long n){
    if (n==0)return inf;
    else return n;
}

signed main(){
    long long n,m,k,q;
    cin>>n>>m>>k>>q;
    vector<pair<long long,long long>> point(k);
    vector<long long> b(q);
    long long maxx = 0;
    for (auto &i:point){cin>>i.first>>i.second;maxx=max(maxx,i.first);}
    vector<long long> linel(m+2),liner(m+2);
    for (auto &i:b){cin>>i;linel[i]=liner[i]=i;}
    for (long long i=1;i<=m;i++){
        if (linel[i]==0)
            linel[i]=linel[i-1];
    }
    for (long long i=m;i>=1;i--){
        if (liner[i]==0)
            liner[i]=liner[i+1];
    }
    map<long long,long long> dp[2];
    sort(point.begin(),point.end());
    if (point.front().first==1){
        dp[1][1]=maxx-1;
    }
    else {
        if (linel[1]) dp[1][linel[1]]=maxx-1+abs(linel[1]-1);
        if (liner[1]) dp[1][liner[1]]=maxx-1+abs(liner[1]-1);
    }
    long long pos = 0;
    long long flag = 1;
    while(pos<k){
        map<long long,long long>&tmpmap = dp[0],&goodmap=dp[1];
        long long now = point[pos].first;
        long long l = inf,r=-1;
        while(point[pos].first==now){
            l=min(l,point[pos].second);
            r=max(r,point[pos].second);
            pos++;
        }
        long long lmin=inf,rmin=inf;
        tmpmap.clear();
        for (auto &i:goodmap){
            if (i.first>=r){
                tmpmap[l]=min(pre(tmpmap[l]),i.second+abs(i.first-l));
            }
            else if (i.first<=l){
                tmpmap[r]=min(pre(tmpmap[r]),i.second+abs(i.first-r));
            }else {
                tmpmap[r]=min(pre(tmpmap[r]),i.second+abs(i.first-l)+abs(r-l));
                tmpmap[l]=min(pre(tmpmap[l]),i.second+abs(i.first-r)+abs(r-l));
            }
        }
        goodmap.clear();
        for (auto &i:tmpmap){
            if (linel[i.first])goodmap[linel[i.first]]=min(pre(goodmap[linel[i.first]]),i.second+abs(i.first-linel[i.first]));
            if (liner[i.first])goodmap[liner[i.first]]=min(pre(goodmap[liner[i.first]]),i.second+abs(i.first-liner[i.first]));
        }
    }
    long long ans = inf;
    for (auto i:dp[0]){ans = min(ans,i.second);}
    cout<<ans<<endl;
}