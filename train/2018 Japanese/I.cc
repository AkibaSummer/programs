#include<bits/stdc++.h>
using namespace std;

int slovebad(vector<pair<int,int>>&input){
    int size=input.size();
    vector<int> l(100005),r(100005);
    for (auto &i:input){
        r[i.first]++;
        l[i.second]++;
    }
    for (int i=1;i<=100000;i++){
        l[i]+=l[i-1];
    }
    for (int i=100000;i>=1;i--){
        r[i]+=r[i+1];
    }
    int ret=0;
    for (auto &i:input){
        ret=max(ret,size-l[i.first]-r[i.second]);
    }
    return ret;
}

int slovegood(vector<int>&input){

}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>input(n);
    for (auto &i:input)cin>>i.first>>i.second;
    sort(input.begin(),input.end());
    cout<<slovebad(input)<<endl;
}