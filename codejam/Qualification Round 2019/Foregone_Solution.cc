#include <bits/stdc++.h>
using namespace std;
void slove(int n){
    int temp = 1;
    int ans1=0,ans2=0;
    while (n){
        if (n%10==4){
            ans1+=2*temp;
            ans2+=2*temp;
        }
        else ans1+=n%10*temp;
        n/=10;
        temp*=10;
    }
    cout<<ans1<<' '<<ans2;
    return ;    
}
int main(){
    int t;
    cin>>t;
    for (int i=1;i<=t;i++){
        int n;
        cin>>n;
        cout<<"Case #"<<i<<": ";
        slove(n);
        cout<<endl;
    }
}