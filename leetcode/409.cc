class Solution {
public:
    int longestPalindrome(string s) {
        map<int,int>orz;
        for (auto &i:s){
            ++orz[i];
        }
        int ret(0),temp(0);
        for (auto &i:orz){
            if (i.second%2){temp=1;ret+=i.second-1;}
            else ret+=i.second;
        }
        return ret+(temp?1:0);
    }
};