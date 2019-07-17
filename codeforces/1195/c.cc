#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

long long input[2][100005];
long long dp[2][100005];
int n;

long long find(int x,int y){
    if (y>n)return 0;
    if (dp[x][y]!=-1)return dp[x][y];
    long long ret1=find(1-x,y+1)+input[1-x][y+1];
    long long ret2=find(1-x,y+2)+input[1-x][y+2];
    return dp[x][y]=max(ret1,ret2);
}

int main(){
    cin>>n;
    for (int i=0;i<2;i++){
        for (int j=1;j<=n;j++){
            cin>>input[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<max(find(0,0),find(1,0))<<endl;
}