#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
struct rec {
    int a,b,c,d;
} u,v;
vector<int> x,y;

char s[12][13];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        x.clear();y.clear();
        
        scanf("%d%d%d%d%d%d%d%d", &u.a,  &u.b,  &u.c,  &u.d, &v.a,  &v.b,  &v.c,  &v.d);
        x.push_back(u.a);x.push_back(v.a);x.push_back(u.c);x.push_back(v.c);
        y.push_back(u.b);y.push_back(v.b);y.push_back(u.d);y.push_back(v.d);    

        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        x.erase(unique(x.begin(),x.end()),x.end());
        y.erase(unique(y.begin(),y.end()),y.end());

        // for(auto s:x)printf("%d ", s); puts("");
        // for(auto s:y)printf("%d ", s); puts("");

        // puts("orz");
        u.a = (lower_bound(x.begin(), x.end(), u.a) - x.begin()) * 2 + 2;
        u.c = (lower_bound(x.begin(), x.end(), u.c) - x.begin()) * 2 + 2;
        u.b = (lower_bound(y.begin(), y.end(), u.b) - y.begin()) * 2 + 2;
        u.d = (lower_bound(y.begin(), y.end(), u.d) - y.begin()) * 2 + 2;

        v.a = (lower_bound(x.begin(), x.end(), v.a) - x.begin()) * 2 + 2;
        v.c = (lower_bound(x.begin(), x.end(), v.c) - x.begin()) * 2 + 2;
        v.b = (lower_bound(y.begin(), y.end(), v.b) - y.begin()) * 2 + 2;
        v.d = (lower_bound(y.begin(), y.end(), v.d) - y.begin()) * 2 + 2;

        // printf("%d %d %d %d %d %d %d %d\n",u.a, u.b, u.c, u.d,v.a, v.b, v.c, v.d);

        for(int i=1;i<=10;i++) {
            memset(s[i]+1, '.',sizeof(char) * 10);
        }

        for(int i=u.a;i<=u.c;i++){
            s[u.b][i]='#';
            s[u.d][i]='#';
        }

        
        for(int i=v.a;i<=v.c;i++){
            s[v.b][i]='#';
            s[v.d][i]='#';
        }

        
        for(int i=u.b;i<=u.d;i++){
            s[i][u.a]='#';
            s[i][u.c]='#';
        }
        
        for(int i=v.b;i<=v.d;i++){
            s[i][v.a]='#';
            s[i][v.c]='#';
        }


        for (int i=0;i<=10;i++){
            s[i][0]='#';
            s[i][10]='#';
            s[0][i]='#';
            s[10][i]='#';
        }
        
        // for(int i=0;i<=11;i++){
        //     puts(s[i]);
        // }

        char tot='0';
        for (int i=1;i<=10;i++){
            for (int j=1;j<=10;j++){
                if (s[i][j]=='.'){
                    queue<pair<int,int>> que;
                    tot++;
                    que.push({i,j});
                    s[i][j]=tot;
                    while(!que.empty()){
                        int i=que.front().first;
                        int j=que.front().second;
                        que.pop();
                        if (s[i][j+1]=='.'){que.push({i,j+1});s[i][j+1]=tot;}
                        if (s[i+1][j]=='.'){que.push({i+1,j});s[i+1][j]=tot;}
                        if (s[i][j-1]=='.'){que.push({i,j-1});s[i][j-1]=tot;}
                        if (s[i-1][j]=='.'){que.push({i-1,j});s[i-1][j]=tot;}
                    }
                }
            }
        }
        
        // for(int i=0;i<=11;i++){
        //     puts(s[i]);
        // }

        printf("%d\n",tot-'0');
        

    }


}
/*
10
1 2 4 4
3 1 6 3

1 0 4 6
1 3 4 5

1 3 4 6
1 0 4 5

1 0 5 10
5 0 10 10

1 0 10 10
5 0 10 10

1 0 4 6
2 1 3 5

2 1 5 7
1 2 7 4

1 0 5 10
1 6 10 10

1 0 4 10
1 2 6 8

1 0 10 10
5 2 10 7

1 0 4 3
1 0 4 3
 */