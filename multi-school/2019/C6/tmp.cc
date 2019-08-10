#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b){
    if (b==0)return a;
    else return gcd(b,a%b);
}

int main(){
    long long a=2ll*3*5*7*11*13*17*19*23*31*37*41*43*47*53;
    int cnt=0;
    for (int i=1;;i++){
        if(gcd(a,i)==1)cnt++;
        if (cnt==100){
            cout<<i<<endl;
            break;
        }
    }
    cout<<a<<endl;
}