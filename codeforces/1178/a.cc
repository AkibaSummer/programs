#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

void slove(){

}

int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    int sum=0,sum1=0;
    int first=0;
    for (auto &i:input){
        cin>>i;
        if (!first)sum1=first=i;
        if (first>=2*i)sum1+=i;
        sum+=i;
    }
    if (sum1<=sum-sum1){
        cout<<0<<endl;
    }
    else {
        vector<int>ans;
        ans.push_back(1);
        for (int i=0;i<input.size();i++){
            if (first>=2*input[i])ans.push_back(i+1);
        }
        cout<<ans.size()<<endl;
        for (auto i:ans)cout<<i<<" ";
    }

}