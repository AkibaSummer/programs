#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


void slove(){
    int n,m;
    cin>>n>>m;
    vector<string> input(n);
    for (auto &i:input){
        cin>>i;
    }
    vector<int> x(n),y(m);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (input[i][j]=='*'){
                x[i]++;
                y[j]++;
            }
        }
    }
    int ans=1<<30;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (input[i][j]=='.')
                ans=min(ans,n+m-x[i]-y[j]-1);
            else ans=min(ans,n+m-x[i]-y[j]);
        }
    }
    cout<<ans<<endl;
    // for (auto i:x){
    //     cout<<i<<' ';
    // }
    // cout<<endl;
    // for (auto i:y){
    //     cout<<i<<' ';
    // }
    // cout<<endl;
}


int main(){
    int n;
    cin>>n;
    while(n--){
        slove();
    }
}