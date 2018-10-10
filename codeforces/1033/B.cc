#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        long long a,b;
        cin>>a>>b;
        if (a-b!=1){
            cout<<"NO"<<endl;
            continue;
        }
        a=(a-b)*(a+b);
        int flag=0;
        b=sqrt(a);
        for (int j=2;j<=b;j++){
            if (a%j==0) {
                cout<<"NO"<<endl;
                flag=1;
                break;
            }
        }
        if (!flag)cout<<"YES"<<endl;
    }
}