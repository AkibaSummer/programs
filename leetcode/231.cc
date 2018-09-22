class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<0) return 0;
        int ret(0);
        while (n){
            ret+=n&1;
            n>>=1;
        }
        return ret==1;
    }
};