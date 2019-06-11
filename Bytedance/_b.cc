#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

map<pair<int,int>,int> ans[2];

int main(){
    int w,b,sum;
    cin>>w>>b;
    sum=w+b;
    int h=0;
    for (;;h++){
        if (h*(h+1)/2>sum)break;
    }
    h--;
    ans[1].insert({{1,0},1});
    ans[1].insert({{0,1},1});
    for (int i=2;i<=h;i++){
        map<pair<int,int>,int> &now=ans[i&1];
        map<pair<int,int>,int> &pre=ans[1-i&1];
        now.clear();
        for (auto &j:pre){
            if (j.first.first+i<=w){
                // if (now.find({j.first.first+i,j.first.second})!=now.end()){
                    now[{j.first.first+i,j.first.second}]+=j.second;
                // }
                // else now[{j.first.first+i,j.first.second}]=j.second;
                now[{j.first.first+i,j.first.second}]%=mod;
            }
            if (j.first.second+i<=b){
                now[{j.first.first,j.first.second+i}]+=j.second;
                now[{j.first.first,j.first.second+i}]%=mod;
            }
        }
    }
    int output=0;
    for (auto i:ans[h&1]){
        output+=i.second;
        output%=mod;
    }
    cout<<h<<' '<<output<<endl;
}