
class Solution {
public:
    const int fix=5;
    int minJump(vector<int>& jump) {
        int n = jump.size();
        vector<int>dp(n);
        queue<pair<int,int>> que;
        que.push({0,0});
        int maxr=0;
        dp[0]=1;
        while(que.size()){
            auto now = que.front();
            que.pop();
            auto pos = now.second;
            auto step = now.first;
            if (pos+jump[pos]>=n){
                return step+1;
            }
            if (dp[pos+jump[pos]]==0){
                dp[pos+jump[pos]]=1;
                que.push({step+1,pos+jump[pos]});
            }
            if (pos>maxr){
                while(maxr<=pos){
                    if (dp[maxr]){
                        maxr++;
                    }
                    else {
                        dp[maxr]=1;
                        que.push({step+1,maxr});
                        maxr++;
                    }
                }
            }
        }
        return 0;
    }
};
