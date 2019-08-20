#include <bits/stdc++.h>
using namespace std;

void slove(){
    
}

int main(){
    int n,l,r;
    cin>>n>>l>>r;
    long long minn=0,maxx=0;
    minn=(1ll<<l)-1+n-l;
    maxx=(1ll<<r)-1+(n-r)*(1ll<<(r-1));
    cout<<minn<<' '<<maxx;
}