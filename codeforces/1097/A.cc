#include <bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cin>>a;
    for (int i=1;i<=5;i++){
        string b;
        cin>>b;
        if (b[0]==a[0]){
            cout<<"YES"<<endl;
            return 0;
        }
        else if (b[1]==a[1]){
            cout<<"YES"<<endl;
            return 0;            
        }
    }
    cout<<"NO"<<endl;    
}