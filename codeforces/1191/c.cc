#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main(){
    long long n,m,k;
    cin>>n>>m>>k;
    vector<long long> input(m);
    for (auto &i:input){
        cin>>i;
    }
    long long right=0;
    long long pos=0;
    long long ans=0;
    while (pos<m){
        long long num=0;
        while(input[pos]<=right&&pos<m){
            pos++;
            num++;
        }
        if (num){
            ans++;
            right+=num;
        }
        else {
            right+=(input[pos]-right-1)/k*k+k;
        }
        // cout<<right<<' '<<ans<<endl;
    }
    // cout<<endl;
    cout<<ans<<endl;
}