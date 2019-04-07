#include <bits/stdc++.h>
using namespace std;
int input[200005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for (int tt=1;tt<=t;tt++){
        int n;
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>input[i];
        }
        input[n+1]=0;
        vector<long long> orz(3,0);
        int flag =1;
        for (int i=1;i<=n+1;i++){
            if (input[i]<input[i-1]){
                orz[2]-=input[i-1]-input[i];
                if (orz[2]<0){
                    flag = 0;
                    break;
                }
            }
            orz[2]+=orz[1];
            orz[1]=orz[0];
            orz[0]=0;
            if (input[i]>input[i-1]){
                orz[0]=input[i]-input[i-1];
            }
        }
        if (flag){
            cout<<"Case #"<<tt<<": Yes"<<endl;
        }
        else {
            cout<<"Case #"<<tt<<": No"<<endl;
        }
    }
}