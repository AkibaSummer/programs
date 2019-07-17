#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int main(){
    long long n,k;
    cin>>n>>k;
    long long l=1,r=n;
    while (true){
        long long mid = (l+r)/2;
        long long judge = (1+mid)*(mid)/2; 
        if (judge == k+n-mid){
            cout<<n-mid<<endl;
            return 0 ;
        }
        else if (judge > k+n-mid){
            r=mid-1;
        }
        else {
            l=mid+1;
        }
    }
    cout<<l<<endl;
}