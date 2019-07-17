#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


bool slove(){
    int n,k;
    cin>>n>>k;
    int p=n/k;
    if (k%3!=0){
        if (n%3==0){
            return false;
        }
        else return true;
    }
    else {
        n=n%(k+1);
        if (n==0){
            return false;
        }
        else if (n==k){
            return true;
        }
        else {
            if (n%3==0){
                return false;
            }
            else return true;
        }
    }
}


int main(){
    int t;
    cin>>t;
    while(t--){
        if (slove()){
            cout<<"Alice"<<endl;
        }
        else {
            cout<<"Bob"<<endl;
        }
    }
}