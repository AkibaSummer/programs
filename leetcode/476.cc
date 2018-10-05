class Solution {
public:
    int findComplement(int num) {
        int ret(0),pos(-1);
        while ((num>>(++pos))){
            ret|=!(num>>pos&1)<<pos;
        }
        return ret;
    }
};