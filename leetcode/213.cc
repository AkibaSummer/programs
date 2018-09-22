class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())return 0;
        int pre(0),preadd1(nums[0]),npre(0),npreadd1(0);
        for (int i=1;i<nums.size();i++){
            int temp(pre);
            pre=npre+nums[i];
            npre=max(temp,npre);
            if (i==nums.size()-1)continue;
            temp=preadd1;
            preadd1=npreadd1+nums[i];
            npreadd1=max(temp,npreadd1);
        }
        return max(max(pre,npre),max(preadd1,npreadd1));
    }
};