#include <bits/stdc++.h>
using namespace std;
#define int long long

int jc[21];

int isused[21];

int getkth(int k){
    int pos =1;
    for (int i=1;i<=k;i++,pos++){
        while(isused[pos])pos++;
    }
    pos--;
    return pos;
}

int n,k;

void nxt(int pos){
    if (pos==n){
        cout<<getkth(1)<<endl;
        return;
    }
    for (int i=1;i<=n;i++){
        if (isused[i])continue;
        else {
            if (k>=jc[n-pos]){
                k-=jc[n-pos];
            }
            else {
                cout<<i<<" ";
                isused[i]=1;
                nxt(pos+1);
                return;
            }
        }
    }
}


void slove(){
    cin>>n>>k;
    memset(isused,0,sizeof(isused));
    k-=1;
    for (int i=n;i>=1;i--){
        if (k>=jc[n-1])k-=jc[n-1];
        else {
            cout<<i<<' ';
            isused[i]=1;
            nxt(2);
            return ;
        };
    }
}

signed main(){
    jc[1]=1;
    for (int i=2;i<=20;i++){
        jc[i]=jc[i-1]*i;
        // cout<<jc[i]<<' ';
    }
    int t;
    cin>>t;
    while(t--){
        slove();
    }
}