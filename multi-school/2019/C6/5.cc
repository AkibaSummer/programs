#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp1(const pair<pair<int,int>,int> &a,const pair<pair<int,int>,int> &b){
    return a.first.first<b.first.first;
}

bool cmp2(const pair<pair<int,int>,int> &a,const pair<pair<int,int>,int>&b){
    return a.first.second<b.first.second;
}


int n;
int cntx=0,cnty=0;
pair<pair<int,int>,int> input[2005];
long long dp[2005][2005];
int num[2005][2005];
set<pair<pair<int,int>,pair<int,int>>> visited;

void init(){
    visited.clear();
    for (int i=1;i<=cntx;i++){
        memset(dp[i],0,sizeof(long long)*(cnty+5));
        memset(num[i],0,sizeof(int)*(cnty+5));
    }
}

inline ll getsum(int i1,int j1,int i2,int j2){
    return dp[i2][j2]-dp[i1-1][j2]-dp[i2][j1-1]+dp[i1-1][j1-1];
}

inline int getnum(int i1,int j1,int i2,int j2){
    return num[i2][j2]-num[i1-1][j2]-num[i2][j1-1]+num[i1-1][j1-1];
}

ll find(int i1,int j1,int i2,int j2){
    if (visited.find({{i1,j1},{i2,j2}})!=visited.end()) return 0ll;
    visited.insert({{i1,j1},{i2,j2}});
    if (getnum(i1,j1,i2,j2)<=1){
        return max(0ll,getsum(i1,j1,i2,j2));
    }
    ll ret = max(0ll,getsum(i1,j1,i2,j2));
    int prenum=-1;
    for (int i=i1;i<i2;i++){
        if (prenum==getnum(i1,j1,i,j2))continue;
        prenum=getnum(i1,j1,i,j2);
        ret=max(ret,max(find(i1,j1,i,j2),find(i+1,j1,i2,j2)));
    }
    prenum=-1;
    for (int j=j1;j<j2;j++){
        if (prenum==getnum(i1,j1,i2,j))continue;
        prenum=getnum(i1,j1,i2,j);
        ret=max(ret,max(find(i1,j1,i2,j),find(i1,j+1,i2,j2)));
    }
    return ret;
}

void slove1(){
    init();
    for (int i=1;i<=n;i++){
        dp[input[i].first.first][input[i].first.second]+=input[i].second;
        num[input[i].first.first][input[i].first.second]++;
    }
    for (int i=1;i<=cntx;i++){
        for (int j=1;j<=cnty;j++){
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            num[i][j]+=num[i-1][j]+num[i][j-1]-num[i-1][j-1];
        }
    }
    printf("%lld\n",find(1,1,cntx,cnty));
}

void slove(){
    cntx=0,cnty=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d%d%d",&input[i].first.first,&input[i].first.second,&input[i].second);
    }
    sort(input+1,input+n+1,cmp1);
    int pre=1e9+5;
    for (int i=1;i<=n;i++){
        if (input[i].first.first==pre){
            input[i].first.first=cntx;
        }
        else {
            pre=input[i].first.first;
            input[i].first.first=++cntx;
        }
    }
    sort(input+1,input+n+1,cmp2);
    pre=1e9+5;
    for (int i=1;i<=n;i++){
        if (input[i].first.second==pre){
            input[i].first.second=cnty;
        }
        else {
            pre=input[i].first.second;
            input[i].first.second=++cnty;
        }
    }
    // for (int i=1;i<=n;i++){
    //     cout<<input[i].first.first<<' '<<input[i].first.second<<' '<<input[i].second<<endl;
    // }
    slove1();
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        slove();
    }
}