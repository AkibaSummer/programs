#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    priority_queue<int,vector<int>,greater<int>> input;
    for (int i=0;i<n;i++){
        int k;cin>>k;
        input.push(k);
    }
    // cout<<input.top();
    int q=n/2;
    while (q--)input.pop();
    int num=1;
    // cout<<input.size()<<endl;
    int tmp=input.top();
    input.pop();
    while (k&&!input.empty()){
        // cout<<input.top()<<endl;
        if ((input.top()-tmp)*num<=k){
            k-=(input.top()-tmp)*num;
            num++;
            tmp=input.top();
            input.pop();
        }
        else break;
    }
    tmp+=k/num;
    cout<<tmp<<endl;
}