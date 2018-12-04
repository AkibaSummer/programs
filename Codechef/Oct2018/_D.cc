#include <bits/stdc++.h>
using namespace std;
bool judge(long long ans,long long maxqiqiu,vector<long long>& a,vector<long long>& b){
    int temp=0;
    for (int i=0;i<a.size();i++){
        temp+=min(a[i],ans/b[i]);
        if (temp>maxqiqiu)return false;
    }
    return true;
}
int main(){
    long long n,m,sum(0);
    cin>>n>>m;
    vector<long long>a(n),b(n);
    for (auto &i:a){cin>>i;sum+=i;}
    for (auto &i:b)cin>>i;
    long long l(0),r(1e18);
    while (l!=r){
        long long mid=(l+r)/2+1;
        if (judge(mid,sum-m,a,b))l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;    
}