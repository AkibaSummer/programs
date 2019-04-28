#include <bits/stdc++.h>
using namespace std;

const int maxx=300005;
int n;
int type[maxx];
vector <int> node[maxx];
int slove (int root){
    if (node[root].empty()){
        return 1;
    }
    else {
        if (type[root]){
            int ret=0x7fffffff; 
            for (auto i:node[root]){
                ret=min(ret,slove(i));
            }
            return ret;
        }
        else {
            int ret=0;
            for (auto i:node[root]){
                ret+=slove(i);
            }
            return ret;
        }
    }
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>type[i];
    }
    for (int i=2;i<=n;i++){
        int temp;
        cin>>temp;
        node[temp].push_back(i);
    }
    cout<<n-slove(1)<<endl;
}