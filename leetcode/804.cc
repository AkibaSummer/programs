class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<pair<long long,int>> ret;
        for (auto &i:words){
            long long temp(0);
            int size(0);
            for (auto j:i){
                switch (j){
                    case 'a':
                        temp<<=2;
                        size+=2;
                        temp|=1;
                        break;
                    case 'b':
                        temp<<=4;
                        size+=4;
                        temp|=8;
                        break;
                    case 'c':
                        temp<<=4;
                        size+=4;
                        temp|=10;
                        break;
                    case 'd':
                        temp<<=3;
                        size+=3;
                        temp|=4;
                        break;
                    case 'e':
                        temp<<=1;
                        size+=1;
                        temp|=0;
                        break;
                    case 'f':
                        temp<<=4;
                        size+=4;
                        temp|=2;
                        break;
                    case 'g':
                        temp<<=3;
                        size+=3;
                        temp|=6;
                        break;
                    case 'h':
                        temp<<=4;
                        size+=4;
                        temp|=0;
                        break;
                    case 'i':
                        temp<<=2;
                        size+=2;
                        temp|=0;
                        break;
                    case 'j':
                        temp<<=4;
                        size+=4;
                        temp|=7;
                        break;
                    case 'k':
                        temp<<=3;
                        size+=3;
                        temp|=5;
                        break;
                    case 'l':
                        temp<<=4;
                        size+=4;
                        temp|=4;
                        break;
                    case 'm':
                        temp<<=2;
                        size+=2;
                        temp|=3;
                        break;
                    case 'n':
                        temp<<=2;
                        size+=2;
                        temp|=2;
                        break;
                    case 'o':
                        temp<<=3;
                        size+=3;
                        temp|=7;
                        break;
                    case 'p':
                        temp<<=4;
                        size+=4;
                        temp|=6;
                        break;
                    case 'q':
                        temp<<=4;
                        size+=4;
                        temp|=13;
                        break;
                    case 'r':
                        temp<<=3;
                        size+=3;
                        temp|=2;
                        break;
                    case 's':
                        temp<<=3;
                        size+=3;
                        temp|=0;
                        break;
                    case 't':
                        temp<<=1;
                        size+=1;
                        temp|=1;
                        break;
                    case 'u':
                        temp<<=3;
                        size+=3;
                        temp|=1;
                        break;
                    case 'v':
                        temp<<=4;
                        size+=4;
                        temp|=1;
                        break;
                    case 'w':
                        temp<<=3;
                        size+=3;
                        temp|=3;
                        break;
                    case 'x':
                        temp<<=4;
                        size+=4;
                        temp|=9;
                        break;
                    case 'y':
                        temp<<=4;
                        size+=4;
                        temp|=11;
                        break;
                    case 'z':
                        temp<<=4;
                        size+=4;
                        temp|=12;
                        break;
                }
            }
            ret.insert({temp,size});
        }
        return ret.size();
    }
};