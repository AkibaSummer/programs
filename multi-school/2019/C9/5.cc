#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        string s;
        cin>>s;
        for (auto &i:s)
        if (i=='y'){
            continue;
        }else if (i=='z'){
            i='b';
            break;
        }
        else break;
        cout<<s<<endl;
    }
}