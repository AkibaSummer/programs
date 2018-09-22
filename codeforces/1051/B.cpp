#include <bits/stdc++.h>
using namespace std;
int main(){
    long long l,r;
    cin>>l>>r;
    if ((r-l+1)/2==0){
        cout<<"NO"<<'\n';
    }
    else {
        cout<<"YES"<<endl;
        for (long long i=l;i<r;i+=2){
            printf("%lld %lld\n",i,i+1);
        }
    }
}