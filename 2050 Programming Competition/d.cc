#include <bits/stdc++.h>
using namespace std;

void slove(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> sch(m+1,0);
    vector<int> q50(m+1,0);
    for (int i=1;i<=n;i++){
         int temp;
         cin>>temp;
         if (i<=n/2)q50[temp]++;
         sch[temp]++;
    }
    int ans=0;
    for (int i=1;i<=m;i++){
        ans+=min(sch[i]/k,q50[i]);
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        slove();
    }
}