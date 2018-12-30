#include <bits/stdc++.h>
using namespace std;

bool slove(vector<int>& orz,int k){
    orz.push_back(k);
    sort(orz.begin(),orz.end());
    reverse(orz.begin(),orz.end());
    
    priority_queue<int> out;
    vector<int>output;
    for (int i=0;i<orz.size();i++){
        while (!out.empty()&&out.top()<i) out.pop();
        output.push_back(orz[i]-out.size());
        out.push(orz[i]-out.size()+i);
    }
    while (!out.empty()&&out.top()<orz.size()) out.pop();
    int bzero=0,ezero=0,szero=0;
    for (auto i:output) {
        if (i>0) bzero++;
        else if (i==0) ezero++;
        else if (i<0) szero++;
    }
    orz.erase(find(orz.begin(),orz.end(),k));
    if (!szero) return true;
}
/*
35
21 26 18 4 28 2 15 13 16 25 6 32 11 5 31 17 9 3 24 33 14 27 29 1 20 4 12 7 10 30 34 8 19 23 22
36
21 26 18 4 28 2 15 13 16 25 6 32 11 5 31 17 9 3 24 33 14 27 29 1 20 4 12 7 10 30 34 8 19 23 22 13
*/
int main(){
    int n;
    cin>>n;
    vector<int> orz(n);
    for (auto &i:orz) cin>>i;
    sort(orz.begin(),orz.end());
    reverse(orz.begin(),orz.end());
    priority_queue<int> out;
    vector<int>output;
    for (int i=0;i<orz.size();i++){
        while (!out.empty()&&out.top()<i) out.pop();
        output.push_back(orz[i]-out.size());
        out.push(orz[i]-out.size()+i);
    }
    while (!out.empty()&&out.top()<orz.size()) out.pop();
    int bzero=0,ezero=0,szero=0;
    for (auto i:output) {
        if (i>0) bzero++;
        else if (i==0) ezero++;
        else if (i<0) szero++;
    } 
    for (auto i:output)cout<<i<<' ';
    puts("");
}