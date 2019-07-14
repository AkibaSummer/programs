#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main(){
    int n;
    cin>>n;
    int k = n % 4;
    if (k==0){
        cout<<"1 A"<<endl;
    }
    if (k==1){
        cout<<"0 A"<<endl;
    }
    if (k==2){
        cout<<"1 B"<<endl;
    }
    if (k==3){
        cout<<"2 A"<<endl;
    }
}