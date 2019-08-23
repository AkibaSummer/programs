#include <bits/stdc++.h>
using namespace std;

#define int long long


int nmd(int k){
    return k+1;
}

void slove(){
    int n;
    cin>>n;
    vector<pair<int,int>>input(n);
    int l=-1,r=1000000+1,ans=0;
    for (auto&i:input){
        cin>>i.first>>i.second;
        if (max(i.first,l)<=min(i.second,r)){
            l=max(i.first,l);
            r=min(i.second,r);
        }
        else {
            if (i.first==i.second){
                ans+=(min(abs(i.first-l),abs(i.first-r))+1)/2;
                l=i.first;
                r=i.second;
            }
            else if (i.second<l){
                if ((l-i.second)%2){
                    ans+=(l-i.second+1)/2;
                    l=i.second-1;
                    r=i.second;
                }
                else {
                    ans+=(l-i.second)/2;
                    l=r=i.second;
                }
            }
            else if (i.first>r){
                if ((i.first-r)%2){
                    ans+=(i.first-r+1)/2;
                    l=i.first;
                    r=i.first+1;
                }
                else {
                    ans+=(i.first-r)/2;
                    l=r=i.first;
                }
            }
            else {
                cout<<nmd(0)<<endl;
            }
        }
    }
    cout<<ans<<endl;   
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        slove();
    }
}