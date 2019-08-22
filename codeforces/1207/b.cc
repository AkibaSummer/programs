#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void slove(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m)), b(n,vector<int>(m));
    for (auto &i:a){
        for (auto &j:i){
            cin>>j;
        }
    }
    vector<pair<int,int>> ans;
    
    for (int i=0;i<n-1;i++){
        for (int j=0;j<m-1;j++){
            if (a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1]){
                b[i][j]=b[i+1][j]=b[i][j+1]=b[i+1][j+1]=1;
                ans.push_back({i,j});
            }
        }
    }

    int flag = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (a[i][j]!=b[i][j])flag=1;
            cerr<<b[i][j]<<' ';
        }
        cerr<<endl;
    }
    if (flag)cout<<-1<<endl;
    else {
        cout<<ans.size()<<endl;
        for (auto &i:ans)cout<<i.first+1<<' '<<i.second+1<<endl;
    }


}

int main(){
    int t;
    // cin>>t;
    t=1;
    while(t--){
        slove();
    }
}