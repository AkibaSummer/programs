#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int gcd(int a,int b){
    if (!a||!b)return a+b;
    return gcd(b,a%b);
}

pair<int,int> getfenshu(int a,int b){
    if (a==0)return {0,1};
    else {
        if (b<0){
            a=-a;b=-b;
        }
        int c = gcd(abs(a),abs(b));
        return {a/c,b/c};
    }
}

double getf(pair<int,int> p){
    return (double)p.first/(double)p.second;
}

bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    return getf(a.first)<getf(b.first);
}

inline int cmppair(pair<int,int> a,pair<int,int>b){
    double aa = getf(a),bb=getf(b);
    if (fabs(aa-bb)<=0.0000001){
        return 0;
    }
    else if (aa>bb)return 1;
    else return -1;
}

void slove(){
    int n,c;
    scanf("%lld%lld",&n,&c);
    vector<pair<int,int>>input(n);
    for (auto &i:input){
        scanf("%lld%lld",&i.first,&i.second);
    }
    vector<pair<pair<int,int>,int>> sorted;
    for (int i=0;i<n;i++){
        sorted.push_back({getfenshu(-input[i].second,input[i].first),i});
    }
    sort(sorted.begin(),sorted.end(),cmp);
    int aa=0,bb=0;
    for (int i=0;i<n;i++){
        aa+=-input[i].first;
        bb+=-input[i].second;
    }
    if (aa==0&&bb==c){
        puts("-1");
        return ;
    }
    vector<pair<int,int>>ans;
    if (cmppair({c-bb,aa},sorted[0].first)<=0){
        ans.push_back(getfenshu(c-bb,aa));
    }
    for (int i=0;i<n-1;i++){
        pair<int,int> &now=input[sorted[i].second];
        aa+=now.first+now.first;
        bb+=now.second+now.second;
        if (aa==0&&bb==c){
            puts("-1");
            return ;
        }
        if (cmppair({c-bb,aa},sorted[i].first)>=0&&cmppair({c-bb,aa},sorted[i+1].first)<=0){
            ans.push_back(getfenshu(c-bb,aa));
        }
    }
    pair<int,int> &now=input[sorted[n-1].second];        
    aa+=now.first+now.first;
    bb+=now.second+now.second;
    if (aa==0&&bb==c){
        puts("-1");
        return ;
    }
    if (cmppair({c-bb,aa},sorted[n-1].first)>=0){
        ans.push_back(getfenshu(c-bb,aa));
    }
    ans.push_back({-1,-1});
    vector<pair<int,int>> ans2;
    for (int i=0;i<ans.size()-1;i++){
        if (ans[i]!=ans[i+1])ans2.push_back(ans[i]);
    }
    printf("%d",ans2.size());
    for (auto &i:ans2){
        printf(" %lld/%lld",i.first,i.second);
    }
    puts("");
}

signed main(){
    int t;
    scanf("%lld",&t);
    while(t--){
        slove();
    }
}