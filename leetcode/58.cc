class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret=0;
        int now=s.length()-1;
        for (;now>=0;now--){
            if (s[now]!=' ')break;
        }
        for (;now>=0;now--){
            if (s[now]==' ')return ret;
            ret++;
        }
        return ret;
    }
};