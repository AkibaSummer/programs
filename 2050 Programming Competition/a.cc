#include <bits/stdc++.h>
using namespace std;

void slove(){
    string in;
    string orz="2050";
    cin>>in;
    int pos=0;
    for (auto i:in){
        if (i!=orz[pos]){
            cout<<"No"<<endl;
            return ;
        }
        pos++;
        pos%=4;
    }
    if (pos==0){
        cout<<"Yes"<<endl;

    }
    else cout<<"No"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        slove();
    }
}