#include <bits/stdc++.h>
using namespace std;


int dp[2010][2010];

int n,k;

void add1(int x1,int y1,int x2,int y2){
    x1++,y1++,x2++,y2++;
    // cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
    dp[x1][y1]++;
    dp[x2+1][y1]--;
    dp[x1][y2+1]--;
    dp[x2+1][y2+1]++;
}

void printdp(){
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++){
    //         cout<<dp[i][j];
    //     }
    //     puts("");
    // }
    // puts("");
}

int main(){
    cin>>n>>k;
    vector<string>input(n);
    for (auto&i:input)cin>>i;
    vector<pair<int,int>>c(n,{n,-1}),r(n,{n,-1});
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (input[i][j]=='B'){
                c[j].first=min(c[j].first,i);
                c[j].second=max(c[j].second,i);
                r[i].first=min(r[i].first,j);
                r[i].second=max(r[i].second,j);//c：列 r：行
            }
        }
    }
    int z=0,ans=0;
    for (int i=0;i<n;i++){
        auto &now=c[i];
        if (now.second==-1)z++;
        else {
            if (now.second-now.first+1<=k){
                add1(i,now.second,min(n-1,i+k-1),min(n-1,now.first+k-1));
            }
        }
    }
    for (int i=0;i<n;i++){
        auto &now=r[i];
        if (now.second==-1)z++;
        else {
            if (now.second-now.first+1<=k){
                add1(now.second,i,min(n-1,now.first+k-1),min(n-1,i+k-1));
            }
        }
    }
    printdp();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            dp[i][j]+=dp[i-1][j];
        }
    }
    printdp();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            dp[i][j]+=dp[i][j-1];
            ans=max(ans,dp[i][j]);
        }
    }
    printdp();
    cout<<ans+z<<endl;
}