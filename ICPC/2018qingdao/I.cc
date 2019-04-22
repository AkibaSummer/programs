#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int a[100005],n;

inline void p1(int pos,set<pair<int,int> >&pre,set<pair<int,int> >&pree){
    set<pair<int,int> > now;
    for (auto &i:pre){
        now.insert({min(i.first,a[pos]),max(i.second,a[pos])});
    }
    for (auto &i:pree){
        now.insert({min(i.first,a[pos]+a[pos-1]),max(i.second,a[pos]+a[pos-1])});
    }
    now.swap(pre);
    now.swap(pree);
}

inline int slove(){
    set<pair<int,int> > pre,pree;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if (n<=2){
        cout<<0<<endl;
    }
    else {
        pre.insert({min(a[1],a[2]),max(a[1],a[2])});
        pre.insert({a[2]+a[1],a[1]+a[2]});
        pree.insert({a[1],a[1]});
        for (int i=3;i<=n;i++){
            p1(i,pre,pree);
        };
        int ans=0x7fffffff;
        for (auto &i:pre){
            ans=min(ans,i.second-i.first);
        }
        
        cout<<ans<<endl;
    }


}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        slove();
    }
}
/*
3
5
-1 4 2 1 1
4
1 3 2 4
1
7
*/