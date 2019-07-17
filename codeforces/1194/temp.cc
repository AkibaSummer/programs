#include <bits/stdc++.h>
using namespace std;
int a[100];
int main(){
    int n,k;
    while (1){
        cin>>k;
        memset(a,0,sizeof(a));
        for (int i=1;i<100;i++){
            a[i]=a[i-1];
            if (i>=2){
                a[i]&=a[i-2];
            }
            if (i>=k){
                a[i]&=a[i-k];
            }
            a[i]=1-a[i];
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
}