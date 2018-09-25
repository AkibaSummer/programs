class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret(0);
        x^=y;
        do {
            ret+=x&1;
        }while (x>>=1);
        return ret;
    }
};