#include <bits/stdc++.h>
using namespace std;
int main(){
    // cout<<(0xf^0x0)<<endl;
    cout<<"? ";
    // cout<<(1<<7);
    for (int i=1;i<=100;i++){
        cout<<i<<" \n"[i==100];
    }
    fflush(stdout);
    int a,b;
    cin>>a;
    cout<<"? ";
    for (int i=1;i<=100;i++){
        cout<<(i<<7)<<" \n"[i==100];
    }
    fflush(stdout);
    cin>>b;
    cout<<"! "<<((a&0x3f80)|(b&0x7f))<<endl;
}