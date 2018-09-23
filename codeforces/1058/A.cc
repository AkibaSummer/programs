#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    std::vector<int> input(n);
    int ans(0);
    for (auto &i:input){
        cin>>i;
        ans|=i;
    }
    cout<<(ans?"HARD":"EASY");
}