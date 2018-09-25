class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ret;
        for (auto i:A)if (!(i%2)) ret.push_back(i);
        for (auto i:A)if (i%2) ret.push_back(i);
        return ret;
    }
};