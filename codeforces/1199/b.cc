#include <bits/stdc++.h>
using namespace std;

double sqr(double a){
    return a*a;
}

int main(){
    double h,l;
    cin>>h>>l;
    cout<<fixed<<setprecision(10)<<(sqr(l)-sqr(h))/2/h<<endl;
}