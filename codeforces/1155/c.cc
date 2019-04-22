#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b){
    return b?gcd(b,a%b):a;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<long long>x(n),p(m);
    long long gg=0,minn=1ll<<61;
    for (auto &i:x){
        cin>>i;
        minn=min(minn,i);
    }
    for (int i=1;i<n;i++){
        gg=gcd(x[i]-x[i-1],gg);
    }
    for (int i=0;i<m;i++){
        cin>>p[i];
        if (gg%p[i]==0){
            cout<<"YES"<<endl;
            cout<<minn<<' '<<i+1<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}