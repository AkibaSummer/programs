//
// Created by oopsvpwowlq on 1/25/19.
//

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main(){
    int t;
    cin>>t;
    while(t--){
        int l1,l2,r1,r2;
        cin>>l1>>r1>>l2>>r2;
        if (l1!=l2)cout<<l1<<' '<<l2<<endl;
        else {
            cout<<r1<<' '<<l2<<endl;
        }
    }
}