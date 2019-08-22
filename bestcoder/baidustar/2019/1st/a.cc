#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

void slove(){
    int n;
    cin>>n;
    vector<int>aa(n),bb(n);
    for (auto &i:aa)cin>>i;
    for (auto &i:bb)cin>>i;
    int ma,mb;
    for (int i=0;i<n;i++){
        if (aa[i])ma=i;
        if (bb[i])mb=i;
    }
    if (ma<mb){
        puts("0/1");
    }
    else if (ma==mb){
        int gcdd=gcd(aa[ma],bb[mb]);
        cout<<aa[ma]/gcdd<<'/'<<bb[mb]/gcdd<<endl;
    }
    else puts("1/0");
}

int main(){
    int t;
    cin>>t;
    while(t--){
        slove();
    }
}