#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> input(n),num(k,0);
    for (auto &i:input) {
        cin >> i;
        num[i-1]++;
    }
    int tot = (n+1)/2,ans=0;
    int t=0;
    for (auto i:num){
        if (i%2==0){
            ans+=i;
            tot-=i/2;
        }
        else {
            ans+=i-1;
            tot-=(i-1)/2;
            t++;
        }
    }
    cout<<ans+min(tot,t)<<endl;   
}