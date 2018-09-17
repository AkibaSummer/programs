#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector <int> input(n);
    for (auto &i:input)cin>>i;
    sort(input.begin(),input.end());
    cout<<input[n-1]-input[0]-n+1<<endl;
    return 0;
}