#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main(){
    long long n;
    cin>>n;
    vector<long long> input(n);
    long long sum=0;
    for (auto &i:input){
        cin>>i;
        sum+=i;
    }
    sort(input.begin(),input.end());
    if (!sum){
        cout<<"cslnb"<<endl;
        return 0;
    }
    if (n>1&&input[0]==input[1]&&input[0]==0){
        cout<<"cslnb"<<endl;
        return 0;
    }
    long long flag = 0;
    for (long long i=0;i<n-1;i++){
        if (input[i]==input[i+1]){
            flag ++;
            input[i]--;
        }
    }
    if (flag >1){
        cout<<"cslnb"<<endl;
        return 0;
    }
    for (long long i=0;i<n-1;i++){
        if (input[i]==input[i+1]){
            cout<<"cslnb"<<endl;
            return 0;
        }
    }
    long long tot = n*(n-1)/2;
    long long sub = sum-tot;
    if (sub%2){
        cout<<"sjfnb"<<endl;
    }
    else {
        cout<<"cslnb"<<endl;
    }
}