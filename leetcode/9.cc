class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)return false;
        int ret(0),input(x);
        while(x){
            ret*=10;
            ret+=x%10;
            x/=10;
        }
        return (ret==input);
    }
};