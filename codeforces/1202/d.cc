#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void slove(){
    int n;
    cin>>n;
    if (n<=99995){
        cout<<"133";
        for (int i=1;i<=n;i++)cout<<"7";
        cout<<endl;
    }
    else {
        int r=sqrt(n);
        for (int i=r;i>=1;i--){
            if (n%i==0&&i+(n/i)+2<=99999){
                for (int j=1;j<=i;j++)cout<<"1";
                cout<<"33";
                for (int j=n/i;j>=1;j--)cout<<"7";
                cout<<endl;
                return ;
            }
            if (i+n/i+5>99999)break;
        }
        for (int i=1;i;i++){
            n--;
            for (int j=r;j>=4;j--){
                if (n%j==0&&j+(n/j)+i+10<=99999){
                    for (int k=n/j;k>=1;k--)cout<<"1";
                    cout<<"3";
                    for (int k=1;k<=i;k++)cout<<"1";
                    cout<<"3";
                    for (int k=1;k<=j-3;k++)cout<<"7";
                    cout<<"37"<<endl;
                    return ;
                }
                if (j+(n/j)+i+20>99999)break;
            }
        }
    }
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        slove();
    }
}