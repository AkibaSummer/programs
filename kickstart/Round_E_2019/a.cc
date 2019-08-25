#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int slove() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<pair<int, int>> input(m);
    vector<vector<int>>links(n);
    vector<int> visted(n);
    for (auto &i : input) {
        cin >> i.first >> i.second;
        if (i.first > i.second)
            swap(i.first, i.second);
            i.first--;i.second--;
        links[i.first].push_back(i.second);
        links[i.second].push_back(i.first);
    }
    int ans=0;
    for (int i=0;i<n;i++){
        if (!visted[i]){
            ans+=2;
            visted[i]=1;
            queue<int> que;
            que.push(i);
            while(que.size()){
                int now=que.front();
                que.pop();
                for (auto &i:links[now]){
                    if(!visted[i]){
                        ans+=1;
                        visted[i]=1;
                        que.push(i);
                    }
                }
            }
        }
    }
    return ans-2;
}

int main() {
    int tt;
    scanf("%d", &tt);
    for (int i = 1; i <= tt; i++) {
        printf("Case #%d: %d\n", i, slove());
    }
}