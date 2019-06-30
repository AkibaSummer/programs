#include <bits/stdc++.h>
using namespace std;
int slove(){
    int a,b,c;
    cin>>a>>b>>c;
    int d,e,f;
    d=a-b;
    e=a-c;
    cout<<(max(d,e)+1)<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--){
        slove();
    }
}