class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> links(n);
        for (auto &i:relation){
            links[i[0]].push_back(i[1]);
        }
        map<int,int> now;
        now[0]=1;
        for (int i=0;i<k;i++){
            map<int,int> nxt;
            for (auto &i:now){
                for (auto &j:links[i.first]){
                    nxt[j]+=i.second;
                }
            }
            now=nxt;
        }
        return now[n-1];
    }
};