#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> room(10);
    for (auto i:s){
        if (i=='L'){
            for (int i=0;i<10;i++){
                if (room[i]==0){room[i]=1;
                break;}
            }
        }
        else if (i=='R'){
            for (int i=9;i>=0;i--){
                if (room[i]==0){room[i]=1;
                break;}
            }
        }
        else room[i-'0']=0;
    }
    for (auto i:room)cout<<i;
}