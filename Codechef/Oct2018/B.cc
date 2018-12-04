#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--){
        int a;
        unsigned long long ans=1;
        cin>>a;
        for (int i=(a-1)/26;i>=1;i--){
            ans*=2;
        }
        if (a%26>=1&&a%26<=2){
            cout<<ans<<' '<<0<<' '<<0<<endl;
        }
        else if (a%26>2&&a%26<=10){
            cout<<0<<' '<<ans<<' '<<0<<endl;
        }
        else {
            cout<<0<<' '<<0<<' '<<ans<<endl;
        }
    }
}