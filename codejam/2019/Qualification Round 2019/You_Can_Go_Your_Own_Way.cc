#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for (int i=1;i<=t;i++){
        int nn;
        cin>>nn;
        string s;
        cin>>s;
        printf("Case #%d: ",i);
        for (auto i:s){
            if (i=='S')printf("E");
            else printf("S");
        }
        printf("\n");
    }
}