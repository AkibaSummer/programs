#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
long long l[100005],tot[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for (int tt=1;tt<=t;tt++){
        int a,b,n;
        cin>>a>>b>>n;
        for (int i=1;i<=a;i++){
            cin>>l[i];
            tot[i]=l[i]+tot[i-1];
            // cout<<l[i]<<' '<<tot[i]<<endl;
        }
        for (int i=1;i<=n;i++){
            int prea=a,preb=b;
            for (int j=a;j>=0;j--){
                if (tot[j]<a){
                    b=a-tot[j];
                    a=j+1;
                    break;
                }
            }
            // cout<<a<<'-'<<b<<endl;
            
            if (a==prea&&b==preb){
                break;
            }
            
        }
        cout<<"Case #"<<tt<<": "<<a<<'-'<<b<<endl;
    }
}