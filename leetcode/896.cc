class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size()<=1)return 1;
        bool retup(0),retdown(0),eq(0);
        for (int i=1;i<A.size();i++){
            eq|=A[i]!=A[i-1];
            retup|=(A[i]>A[i-1]);
            retdown|=(A[i]<A[i-1]);
        }
        return !eq|(retup^retdown);
    }
};