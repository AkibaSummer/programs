#include<bits/stdc++.h>
using namespace std;
int main(){

    cout<<"1 2"<<endl;
        unsigned long long r1=1,r2=2,r3=3,r4=4,r5=5,r6=6;
        for (int i=1;i<=500;i++){
            if (i%1==0){
                r1<<=1;
            }
            if (i%2==0){
                r2<<=1;
            }
            if (i%3==0){
                r3<<=1;
            }
            if (i%4==0){
                r4<<=1;
            }
            if (i%5==0){
                r5<<=1;
            }
            if (i%6==0){
                r6<<=1;
            }
            if (i==185)cout<<r1+r2+r3+r4+r5+r6<<endl;
            if (i==54)cout<<r1+r2+r3+r4+r5+r6<<endl;
        }
        cout<<1<<endl;
    // }
}