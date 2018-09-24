class Solution {
public:
    int titleToNumber(string s) {
        int ret(0);
        for (auto i:s){
            ret=ret*26+i-'A'+1;
        }
        return ret;
    }
};