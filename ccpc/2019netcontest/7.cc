#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
char output[2050][2050];
int main(){
    output[1][1]='C';
    output[1][2]='C';
    output[2][1]='P';
    output[2][2]='C';
    for (int i=1;i<=10;i++){
        for (int j=(1<<i)+1;j<=2<<i;j++){
            for (int k=1;k<=1<<i;k++){
                output[j][k]=output[j-(1<<i)][k]=='C'?'P':'C';
            }
        }
        for (int j=(1<<i)+1;j<=2<<i;j++){
            for (int k=(1<<i)+1;k<=2<<i;k++){
                output[j][k]=output[j-(1<<i)][k-(1<<i)];
            }
        }
        for (int j=1;j<=1<<i;j++){
            for (int k=(1<<i)+1;k<=2<<i;k++){
                output[j][k]=output[j][k-(1<<i)];
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for (int i=1;i<=1<<n;i++){
            for (int j=1;j<=1<<n;j++){
                cout<<output[i][j];
            }
            cout<<endl;
        }
    }
}