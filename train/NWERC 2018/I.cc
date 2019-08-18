#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    for (auto &i:input)cin>>i;
    double minn=100000;
    sort(input.begin(),input.end());
    for (int i=0;i<n;i++){
        minn=min(minn,1.0*input[i]/(i+1));
        if (input[i]>(i+1)){
            puts("impossible");
            return 0;
        }
    }
    cout<<fixed<<minn<<endl;
}