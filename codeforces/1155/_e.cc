#include <bits/stdc++.h>
using namespace std;
long long inv(long long a,long long m){
    if (a==1)return 1;
    else return inv(m%a,m)*(m-m/a)%m;
}
struct orz{
    long long xi[20]={0};
    long long getans(long long k){
        long long ret=0;
        for (long long i=0;i<20;i++){
            long long tt=1;
            for (long long j=1;j<=i;j++){
                tt*=k;
                tt%=1000003;
            }
            ret+=tt*xi[i];
            ret%=1000003;
        }
        return ret;
    }
    orz operator*(const orz k)const{
        orz ret;
        for (long long i=0;i<20;i++){
            for (long long j=0;j<20-i;j++){
                ret.xi[i+j]+=xi[i]*k.xi[j];
            }
        }
        return ret;
    }
    orz operator+(const orz k)const{
        orz ret;
        for (long long i=0;i<20;i++){
            ret.xi[i]=xi[i]+k.xi[i];
        }
        return ret;
    }
    orz operator/(const long long k)const{
        orz ret;
        for (long long i=0;i<20;i++){
            if (xi[i]!=0){
                ret.xi[i]=inv(xi[i],1000003);
            }
        }
        return ret;
    }
    orz operator*(const long long k)const{
        orz ret;
        for (long long i=0;i<20;i++){
            if (xi[i]!=0){
                ret.xi[i]=xi[i]*k%1000003;
            }
        }
        return ret;
    }

};
int main(){
    for (long long i=0;i<=10;i++){
        cout<<"? "<<i<<endl;
    }
    fflush;
    vector<long long>ans(20);
    for (long long i=0;i<=10;i++){
        cin>>ans[i];
    }
    vector<orz> l(20);
    for (long long i=0;i<=10;i++){
        l[i].xi[0]=1;
        long long tempb=1;
        for (long long j=0;j<=10;j++){
            if (j==i)continue;
            orz temp;
            temp.xi[1]=1;
            temp.xi[0]=-j;
            l[i]=l[i]*temp;
            tempb*=i-j;
        }
        while (tempb<0){
            tempb+=1000003;
        }
        while (tempb>1000003){
            tempb-=1000003;
        }
        l[i]=l[i]/tempb;
    }
    orz p;
    for (long long i=0;i<=10;i++){
        p=p+l[i]*ans[i];
    }
    for (int i=0;i<1000003;i++){
        if (p.getans(i)%1000003==0){
            cout<<"! "<<i<<endl;
            return 0;
        }
    }
    cout<<"! -1"<<endl;
}