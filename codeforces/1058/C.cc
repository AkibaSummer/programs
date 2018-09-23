#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool flag=0;
    int sums(0);
    for (auto i:s)sums+=i-'0';
    if (sums==0){cout<<"YES"<<endl;return 0;}
    for (int i=0;i<sums;i++){
        int sum=0;
        for (auto j:s){
            if (sum+j-'0'==i)sum=0;
            else sum+=j-'0';
            
        }
        if (sum==0)flag=1;
    }
    cout<<(flag?"YES":"NO")<<endl;
}