#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long>input(n);
    vector<char>type(n);
    vector<int>shi(n);
    vector<int>duoyu(n);
    for (auto &i:input)cin>>i;
    for (auto &i:type)cin>>i;
        if (type[0]=='G') shi[0]=5;
        if (type[0]=='L') shi[0]=100;
        if (type[0]=='S') shi[0]=3;
    for (int i=1;i<n;i++){
        if (type[i]=='G') shi[i]=min(shi[i-1],5);
        if (type[i]=='L') shi[i]=min(shi[i-1],100);
        if (type[i]=='S') shi[i]=min(shi[i-1],3);
    }
    long long ans=0;
    
    
}