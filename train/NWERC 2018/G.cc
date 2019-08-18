#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int nowx=0,nowy=0;
    vector<pair<int,int>> ans;
    map<int,map<int,int>> maps;
    for (int i=0;i<s.size();i++){
        if (s[i]=='L'){
            int flag=0;
            int tmpmax=-10000000;
            for (auto &j:ans){
                if (j.second==nowy&&j.first<nowx){
                    tmpmax=max(tmpmax,j.first+1);
                    // nowx=j.first+1;
                    flag=1;
                }
            }
            if (flag==0){
                ans.push_back({-i*2-2,nowy});
                nowx=-i*2-1;
            }
            else nowx=tmpmax;
        }
        else if (s[i]=='R'){
            int flag=0;
            int tmpmin=10000000;
            for (auto &j:ans){
                if (j.second==nowy&&j.first>nowx){
                    // nowx=j.first-1;
                    tmpmin=min(tmpmin,j.first-1);
                    flag=1;
                    // break;
                }
            }
            if (flag==0){
                ans.push_back({i*2+2,nowy});
                nowx=i*2+1;
            }
            else nowx=tmpmin;
        }
        else if (s[i]=='U'){
            int flag=0;
            int tmpmin=10000000;
            for (auto &j:ans){
                if (j.first==nowx&&j.second>nowy){
                    // nowy=j.second-1;
                    tmpmin=min(tmpmin,j.second-1);
                    flag=1;
                    // break;
                }
            }
            if (flag==0){
                ans.push_back({nowx,i*2+2});
                nowy=i*2+1;
            }
            else nowy=tmpmin;
        }
        else if (s[i]=='D'){
            int flag=0;
            int tmpmax=-10000000;
            for (auto &j:ans){
                if (j.first==nowx&&j.second<nowy){
                    // nowy=j.second+1;
                    tmpmax=max(tmpmax,j.second+1);
                    flag=1;
                    // break;
                }
            }
            if (flag==0){
                ans.push_back({nowx,-i*2-2});
                nowy=-i*2-1;
            }
            else nowy=tmpmax;
        }
    }
    int tmpx=0,tmpy=0;
    for (int i=0;i<s.size();i++){
        if (s[i]=='L'){
            for (;;){
                maps[tmpx][tmpy]++;
                int flag=0;
                for (auto &i:ans){
                    if (i.first==tmpx-1&&i.second==tmpy){
                        flag=1;
                        break;
                    }
                }
                if (flag)break;
                else tmpx--;
            }
        }
        if (s[i]=='R'){
            for (;;){
                maps[tmpx][tmpy]++;
                int flag=0;
                for (auto &i:ans){
                    if (i.first==tmpx+1&&i.second==tmpy){
                        flag=1;
                        break;
                    }
                }
                if (flag)break;
                else tmpx++;
            }
        }
        if (s[i]=='U'){
            for (;;){
                maps[tmpx][tmpy]++;
                int flag=0;
                for (auto &i:ans){
                    if (i.first==tmpx&&i.second==tmpy+1){
                        flag=1;
                        break;
                    }
                }
                if (flag)break;
                else tmpy++;
            }
        }
        if (s[i]=='D'){
            for (;;){
                maps[tmpx][tmpy]++;
                int flag=0;
                for (auto &i:ans){
                    if (i.first==tmpx&&i.second==tmpy-1){
                        flag=1;
                        break;
                    }
                }
                if (flag)break;
                else tmpy--;
            }
        }
    }
    // cout<<maps[tmpx][tmpy]<<endl;
    if (maps[tmpx][tmpy]==1){
        cout<<-tmpx<<' '<<-tmpy<<endl;
        cout<<ans.size()<<endl;
        for (auto &i:ans){
            cout<<i.first-tmpx<<' '<<i.second-tmpy<<endl;
        }
    }
    else cout<<"impossible"<<endl;
}