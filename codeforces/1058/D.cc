#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    long long n,m,k,s;
    cin>>n>>m>>k;
    if (n*m*2%k!=0){cout<<"NO"<<endl;}
    else {
        s=n*m*2/k;
        int res1,res2;
        res1=gcd(n,k);
        if (2*res1<=n) res1*=2;
        res2=s/res1;
        if (res1<=n&&res2<=m){
            cout<<"YES"<<endl;
            cout<<0<<' '<<0<<endl;
            cout<<0<<' '<<res2<<endl;
            cout<<res1<<' '<<0<<endl;
        }
        else {
            res2=gcd(m,k);
            if (2*res2<=m)res2*=2;
            res1=s/res2;
            if (res1<=n&&res2<=m){
                cout<<"YES"<<endl;
                cout<<0<<' '<<0<<endl;
                cout<<0<<' '<<res2<<endl;
                cout<<res1<<' '<<0<<endl;
            }
            else cout<<"NO"<<endl;
        }
        
        cout<<res1<<endl<<res2<<endl<<s<<endl;
    }
}