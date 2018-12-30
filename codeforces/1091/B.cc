#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long ansx=0,ansy=0;
    long long a,b;
    for (int i=1;i<=n;i++){
        cin>>a>>b;
        ansx+=a;ansy+=b;
    }
    
    for (int i=1;i<=n;i++){
        cin>>a>>b;
        ansx+=a;ansy+=b;
    }
    cout<<ansx/n<<' '<<ansy/n<<endl;
}