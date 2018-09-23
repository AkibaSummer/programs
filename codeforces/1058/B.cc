#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,d,m;
    cin>>n>>d;
    cin>>m;
    while (m--){
        int x,y;
        cin>>x>>y;
        cout<<((x+y>=d)&&(x+y<=2*n-d)&&(x-d<=y)&&(x+d>=y)?"YES":"NO")<<endl;
        //cout<<(x+y>=d)<<(x+y<=2*n-d)<<(x-d<=y)<<(x+d>=y)<<endl;
    }
}