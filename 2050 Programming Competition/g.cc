#include<bits/stdc++.h>
using namespace std;

int z[1005],x[1005];

void slove(){
    vector<int> qz[1005];
    int w,h,n,m;
    cin>>w>>h>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>z[i];
    }
    for (int i=1;i<=m;i++){
        cin>>x[i];
    }
    sort(z+1,z+1+n);
    sort(x+1,x+1+m);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (z[i]-x[j]<=2*h&&z[i]>=x[j]&&z[i]+x[j]>=0&&z[i]+x[j]<=w*2){
                qz[i].push_back(j);
            }
        }
    }

    long long ans = 0;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if (!qz[i].empty()&&!qz[j].empty()) {
                int l=max(qz[i][0],qz[j][0]);
                int r=min(qz[i][qz[i].size()-1],qz[j][qz[j].size()-1]);
                int ll=lower_bound(qz[i].begin(),qz[i].end(),l)-qz[i].begin();
                int rr=lower_bound(qz[i].begin(),qz[i].end(),r)-qz[i].begin();
                if (ll!=qz[i].size()&&rr!=qz[i].size()&&qz[i][ll]==l&&qz[i][rr]==r){
                    ans+=(rr-ll)*(j-i);
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        slove();
    }
}