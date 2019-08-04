#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long sum=0;
    vector<long long> input(n);
    long long maxx = 0;
    for (auto&i:input){cin>>i;maxx=max(maxx,i);sum+=i;}
    if (sum%2==1)cout<<"NO"<<endl;
    else if (sum<maxx*2)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}