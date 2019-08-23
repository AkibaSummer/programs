#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main(){

    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        if (n==1)cout<<1<<endl;
        else if(n==2)cout<<1<<endl;
        else{
            int k=n%6;
            if (k==0){
                cout<<n/2<<endl;
            }
            if (k==1){
                cout<<n-n/6*2<<endl;
            }
            if (k==2){
                cout<<n/2<<endl;
            }
            if (k==3){
                cout<<n/6<<endl;
            }
            if (k==4){
                cout<<n-1<<endl;
            }
            if (k==5){
                cout<<n/6<<endl;
            }
        }
    }
}