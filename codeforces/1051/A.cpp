#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while (n--){
        string s;
        cin>>s;
        int big(0),small(0),num(0);
        for (auto i:s){
            if (i>='A'&&i<='Z')big++;
            else if (i>='a'&&i<='z')small++;
            else num++;
        }
        if (!num&&big&&small){
            for (auto &i:s){
                if (i>='A'&&i<='Z'&&big>1){i='0';break;}
                else if (i>='a'&&i<='z'&&small>1){i='0';break;}
            }
        }
        else if (num&&!big&&small){
            for (auto &i:s){
                if (i>='0'&&i<='9'&&num>1){i='A';break;}
                else if (i>='a'&&i<='z'&&small>1){i='A';break;}
            }
        }
        else if (num&&big&&!small){
            for (auto &i:s){
                if (i>='A'&&i<='Z'&&big>1){i='a';break;}
                else if (i>='0'&&i<='9'&&num>1){i='a';break;}
            }
        }
        else if (!num&&!big&&small){
            s[0]='0';
            s[1]='A';
        }
        else if (!num&&big&&!small){
            s[0]='0';
            s[1]='a';
        }
        else if (num&&!big&&!small){
            s[0]='a';
            s[1]='A';
        }
        cout<<s<<endl;
    }
    return 0;
}