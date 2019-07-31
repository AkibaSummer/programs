#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int bitnum(int n){
    int ret=0;
    while (n){
        ret+=n&1;
        n>>=1;
    }
    return ret;
}

int findf0(int n){
    int ret = 0;
    while (!((~n)&1)){
        ret++;
        n>>=1;
    }
    return ret;
}

void slove(){
    int n;
    cin>>n;
    if (bitnum(n+1)==1){
        cout<<1<<endl;
    }
    else cout<<0<<endl;
    for (int i=2;i<=n;i++){
        if (i==n&&bitnum(i+1)==1){
            cout<<1<<endl;
        }
        else cout<<(1<<findf0(i))<<" \n"[i==n];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        slove();
    }
}