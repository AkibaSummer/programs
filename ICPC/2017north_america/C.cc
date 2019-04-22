#include <bits/stdc++.h>
using namespace std;
 int main(){
     string a;
     cin>>a;
     string b=a.substr(0,a.length()/2),c=a.substr(a.length()/2);
     int numb=0,numc=0;
     for (auto i:b){
         numb+=i-'A';
     }
     for (auto i:c){
         numc+=i-'A';
     }
     for (auto &i:b){
         i=(i-'A'+numb)%26+'A';
     }
     for (auto &i:c){
         i=(i-'A'+numc)%26+'A';
     }
     for (int i=0;i<b.length();i++){
         cout<<(char)((b[i]-'A'+c[i]-'A')%26+'A');
     }
 }