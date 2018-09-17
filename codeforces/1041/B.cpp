#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
    return b?gcd(b,a%b):a;
}
int main(){
    long long a,b,x,y;
    cin>>a>>b>>x>>y;
    cout<<min(a/(x/gcd(x,y)),b/(y/gcd(x,y)))<<endl;
    return 0;
}
/*
1000000000000000000 
1000000000000000000 
999999866000004473 
999999822000007597
*/