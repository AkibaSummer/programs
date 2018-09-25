class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> Jewels;
        for (auto i:J)Jewels.insert(i);
        int ret(0);
        for (auto i:S)if (Jewels.find(i)!=Jewels.end())ret++;
        return ret;
    }
};