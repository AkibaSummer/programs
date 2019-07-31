#include <bits/stdc++.h>
using namespace std;

void slove(int t){
    int n,g,m;
    cin>>n>>g>>m;
    vector<pair<int,vector<int> > > vecc(n+1),veca(n+1);
    // long long cs=-1,vs=-1;
    for (int i=1;i<=g;i++){
        char c;int s;
        cin>>s>>c;
        if (c=='C'){
            s=(s-1+m)%n+1;
            vecc[s].first=m;
            vecc[s].second.push_back(i);
        }
        else if (c=='A'){
            s=(s-1-m+(1<<30)/n*n)%n+1;
            veca[s].first=m;
            veca[s].second.push_back(i);
        }
    }

    for (int i=n-1;i>=1;i--){
        if (vecc[i].first<=vecc[i+1].first-1){
            vecc[i].first=vecc[i+1].first-1;
            vecc[i].second=vecc[i+1].second;
        }
    }
    if (vecc[n].first<=vecc[1].first-1){
        vecc[n].first=vecc[1].first-1;
        vecc[n].second=vecc[1].second;
    }
    for (int i=n-1;i>=1;i--){
        if (vecc[i].first<=vecc[i+1].first-1){
            vecc[i].first=vecc[i+1].first-1;
            vecc[i].second=vecc[i+1].second;
        }
    }
    if (vecc[n].first<=vecc[1].first-1){
        vecc[n].first=vecc[1].first-1;
        vecc[n].second=vecc[1].second;
    }

    for (int i=2;i<=n;i++){
        if (veca[i].first<=veca[i-1].first-1){
            veca[i].first=veca[i-1].first-1;
            veca[i].second=veca[i-1].second;
        }
    }
    if (veca[1].first<=veca[n].first-1){
        veca[1].first=veca[n].first-1;
        veca[1].second=veca[n].second;
    }
    for (int i=2;i<=n;i++){
        if (veca[i].first<=veca[i-1].first-1){
            veca[i].first=veca[i-1].first-1;
            veca[i].second=veca[i-1].second;
        }
    }
    if (veca[1].first<=veca[n].first-1){
        veca[1].first=veca[n].first-1;
        veca[1].second=veca[n].second;
    }

    vector<int> ans(g+1);
    for (int i=1;i<=n;i++){
        if (veca[i].first==vecc[i].first){
            for (auto j:veca[i].second){
                ans[j]++;
            }
            for (auto j:vecc[i].second){
                ans[j]++;
            }
        }
        else if (veca[i].first>vecc[i].first){
            for (auto j:veca[i].second){
                ans[j]++;
            }
        }
        else if (vecc[i].first>veca[i].first){
            for (auto j:vecc[i].second){
                ans[j]++;
            }
        }
    }
    cout<<"Case #"<<t<<": ";

    for (int i=1;i<=g;i++){
        cout<<ans[i]<<" \n"[i==g];
    }
}

int main(){
    int t;
    cin>>t;
    for (int ttt=1;ttt<=t;ttt++){
        slove(ttt);
    }
}