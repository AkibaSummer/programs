//88ms
class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        for(char i='1';i<=n+'0';i++){
            ret+=i;
        }
        for (int i=1;i<k;i++){
            next_permutation(ret.begin(),ret.end());
        }
        return ret;
    }
};

