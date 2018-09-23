#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,k,s;
    cin>>n>>m>>k;
    if (n*m*2%k!=0){cout<<"NO"<<endl;}
    else {
        s=n*m*2/k;
        for (int i=min(min(n,m),sqrt(s));i!=0;i--){
            if (s%i=0&&s/i<=max(n,m)){
                if (n<=m){
                    cout<<i<<' '<<0<<endl;
                    cout<<0<<' '<<0<<endl;
                    cout<<0<<' '<<s/i<<endl;
                }
                else if (n<=m){
                    cout<<i<<' '<<0<<endl;
                    cout<<0<<' '<<0<<endl;
                    cout<<0<<' '<<s/i<<endl;
                }
            }
            
        }
    }
}