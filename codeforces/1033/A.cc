#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ax,ay,bx,by,cx,cy;
    cin>>n;
    cin>>ax>>ay;
    cin>>bx>>by;
    cin>>cx>>cy;
    cout<<((bx<ax)==(cx<ax)&&(by<ay)==(cy<ay)?"YES":"NO")<<endl;
}