#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,mm,maxx(0);
    cin>>n>>m;
    mm=m;
    vector<int>input(n);
    for(auto &i:input){
        cin>>i;
        m+=i;
        maxx=max(i,maxx);
    }
    cout<<max((m+n-1)/n,maxx)<<' '<<maxx+mm<<endl;
    return 0;
}