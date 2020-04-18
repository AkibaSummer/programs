#pragma GCC O(3)
class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        int n=increase.size();
        int m=requirements.size();
        vector<int> l1(n);
        vector<int> l2(n);
        vector<int> l3(n);
        l1[0]=increase[0][0];
        l2[0]=increase[0][1];
        l3[0]=increase[0][2];
            // cout<<0<<' '<<l1[0]<<' '<<l2[0]<<' '<<l3[0]<<endl;
        for (int i=1;i<n;i++){
            l1[i]=l1[i-1]+increase[i][0];
            l2[i]=l2[i-1]+increase[i][1];
            l3[i]=l3[i-1]+increase[i][2];
            // cout<<i<<' '<<l1[i]<<' '<<l2[i]<<' '<<l3[i]<<endl;
        }
        vector<int> ret(m,-1);
        for (int i=0;i<m;i++){
            if (requirements[i][0]==0&&requirements[i][1]==0&&requirements[i][2]==0){
                ret[i]=0;
                continue;
            }
            auto ll1=lower_bound(l1.begin(),l1.end(),requirements[i][0]);
            auto ll2=lower_bound(l2.begin(),l2.end(),requirements[i][1]);
            auto ll3=lower_bound(l3.begin(),l3.end(),requirements[i][2]);
            if (ll1==l1.end()||ll2==l2.end()||ll3==l3.end()){
                // if (requirements[i][0]<=l1[n-1]&&requirements[i][1]<=l2[n-1]&&requirements[i][2]<=l3[n-1]){
                //     ret[i]=n;
                // }
                continue;
            }
            else {
                ret[i]=max(ll1-l1.begin(),max(ll2-l2.begin(),ll3-l3.begin()))+1;
            }
        }
        return ret;
        
    }
};
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);