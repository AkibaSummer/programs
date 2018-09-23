static const auto __=[]()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    string reverseWords(string s) {
        int pos(0);
        for (int i=0;i<s.size();i++){
            if (s[i]==' '){reverse(s.begin()+pos,s.begin()+i);pos=++i;};
        }
        reverse(s.begin()+pos,s.end());
        return s;
    }
};