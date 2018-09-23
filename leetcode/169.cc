// O(log(n))
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>maps;
        int ret(nums[0]);
        for (auto i:nums){
            maps[i]++;
            if (maps[i]>maps[ret])ret=i;
        }
        return ret;
    }
};

//O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret,temp(0);
        for (auto &i:nums){
            if (ret==i||!temp){++temp;ret=i;}
            else --temp;
        }
        return ret;
    }
};