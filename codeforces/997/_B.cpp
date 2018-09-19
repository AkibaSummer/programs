#include <bits/stdc++.h>
using namespace std;

long long getans(int n,int k){
    if (n==1)return k;
    long long ret=0;
    for (int i=1;i<=k;i++){
        ret+=getans(n-1,i);
    }
    return ret;
}
int main(){
    int n,k;
    while(cin>>n>>k){
        cout<<getans(n,k)<<endl;
    };
    
}