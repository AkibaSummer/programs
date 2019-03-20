#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--){
        int a,b;
        cin>>a>>b;
        int c;
        cin>>c;
        while (true){
            int m=(a+b)/2;
            cout<<m<<endl;
            string s;
            cin>>s;
            if (s=="CORRECT")break;
            else if (s=="TOO_SMALL"){
                a=m+1;
            }
            else b=m-1;
        }
    }
}