#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,k;
    string str,str1="jessie";
    cin>>t;
    while(t--){
        cin>>str;
        for(i=0;i<str.size();i++){
            str[i]=tolower(str[i]);
        }
        if(str==str1){
            cout<<"Good guy!"<<endl;
        }
        else cout<<"Dare you say that again?"<<endl;
    }

    return 0;
}