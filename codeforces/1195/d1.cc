#include<bits/stdc++.h>
using namespace std;

#define endl "\n"


// long long dig(long long n){
//     if (n)return 1+dig(n/10);
//     return 0;
// }

int main(){
    long long n;
    cin>>n;
    vector<long long>input(n);
    vector<long long>digital(1000);
    for (auto &i:input){
        cin>>i;
        // digital[dig(i)]++;
        long long k=0,p=i;
        while (p){
            digital[k]+=p%10;
            p/=10;
            k+=2;            
        }
        p=i,k=1;
        while (p){
            digital[k]+=p%10;
            p/=10;
            k+=2;            
        }
    }
    for (auto &i:digital){
        i*=n;
    }
    vector<long long> output;
    long long k=0;
    for (auto &i:digital){
        k=k+i;
        output.push_back(k%10);
        k/=10;
    }
    long long flag=0;
    long long ans=0;
    for (long long i=output.size()-1;i--;i>=0){
        flag|=output[i];
        ans*=10;
        ans+=output[i];
        ans%=998244353;
    }
    cout<<ans<<endl;
}