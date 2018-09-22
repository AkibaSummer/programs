class Solution {
public:
    int rob(vector<int>& nums) {
        long long pre(0),npre(0);
        for (auto&i:nums){
            long long temp(pre);
            pre=npre+i;
            npre=max(temp,npre);
        }
        return max(pre,npre);
    }
};