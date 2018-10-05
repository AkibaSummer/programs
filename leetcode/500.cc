class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        set<char>q={'Q','W','E','R','T','Y','U','I','O','P',
                   'q','w','e','r','t','y','u','i','o','p'};
        set<char>a={'A','S','D','F','G','H','J','K','L',
                    'a','s','d','f','g','h','j','k','l'};
        set<char>z={'Z','X','C','V','B','N','M',
                    'z','x','c','v','b','n','m'};
        vector<string>ret;
        for (auto &i:words){
            int flagq(0),flaga(0),flagz(0);
            for (auto j:i){
                if (q.find(j)!=q.end())flagq|=1;
                if (a.find(j)!=a.end())flaga|=1;
                if (z.find(j)!=z.end())flagz|=1;
            }
            if (flagq+flaga+flagz==1)ret.push_back(i);
        }        
        return ret;
    }
};