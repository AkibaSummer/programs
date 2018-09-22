class Solution {
private:
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.empty())return 0;
        sort(points.begin(),points.end(),[](const pair<int, int>&a,const pair<int, int>&b){return a.second<b.second;});
        int pos(points[0].second),ans(1);
        for (auto &i:points){
            if (i.first>pos){
                pos=i.second;
                ans++;
            }
        }
        return ans;        
    }
};