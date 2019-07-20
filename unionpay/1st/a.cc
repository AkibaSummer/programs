#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

void slove(){
    long long n,k,m;
    string s;
    cin>>n>>k>>m;
    cin>>s;
    long long maxsum=0,sum=0;
    for (auto i:s){
        if (i=='1'){
            sum++;
            maxsum=max(sum,maxsum);
        }
        else if (i=='0'){
            if (k)k--;
            else {
                sum--;
            }
        }
    }
    long long ans = sum*(m-1)+maxsum;
    if (sum>0)cout<<ans<<endl;
    else cout<<maxsum<<endl;
}

int main(){
    long long t;
    cin>>t;
    for (long long i=1;i<=t;i++){
        slove();
    }
}