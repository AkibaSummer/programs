class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ret(0);
        for (int i=0;i<flowerbed.size();i++){
            if (flowerbed[i-1==-1?0:i-1]+flowerbed[i]+flowerbed[i+1==flowerbed.size()?flowerbed.size()-1:i+1]==0){
                flowerbed[i]=1;
                ++ret;
            }
        }
        return ret>=n;
    }
};