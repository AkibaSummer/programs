#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        string s1,s2;
        cin>>s1>>s2;
        s1=" "+s1;
        s2=" "+s2;
        int s1l=s1.length(),s2l=s2.length();
        int pos1=0,pos2=0;
        for (pos1=0;pos1<s1l;pos1++){
            if (s1[pos1]==s2[pos2]){
                pos2++;
            }
            else {
                pos1--;
                int tmp=pos2;
                while(pos2<s2l&&s2[pos2]==s2[pos2-1])pos2++;
                if (pos2==tmp){
                    // puts("NO");
                    break;
                }
            }
        }
        while(pos2<s2l&&s2[pos2]==s2[pos2-1])pos2++;
        if (pos1==s1l&&pos2==s2l)puts("YES");
        else puts("NO");
    }
}