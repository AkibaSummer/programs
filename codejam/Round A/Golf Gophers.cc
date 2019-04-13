#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int orz[]={16,9,5,7,11,13,17};
const int orzz[]={16,144,720,5040,55440,720720,12252240};
int ans[10];


void slove(){
    for (int i=0;i<7;i++){
        for (int j=1;j<=18;j++){
            cout<<orz[i]<<' ';
        }
        cout<<endl;
        fflush;
        int temp,tot=0;
        for (int j=1;j<=18;j++){
            cin>>temp;
            tot+=temp;
        }
        ans[i]=tot%orz[i];
    }
    int ret=ans[0];
    for (int i=0;i<7;i++){
        if (ret%orz[i]==ans[i])continue;
        while(ret%orz[i]!=ans[i]){
            ret+=orzz[i-1];
        }
    }
    cout<<ret<<endl;
}
int main(){
    int t,n,m;
    cin>>t>>n>>m;
    while (t--){
        slove();
        int ans;
        cin>>ans;
        if (ans==1)continue;
        else break;
    }
}
/*
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
*/