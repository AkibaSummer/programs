#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

char c;
vector<int> player1(15);
vector<int> player2(15);
vector<int> player3(15);
vector<int> player4(15);
vector<int> table(15);
void init(){
    player1.resize(0);
    player1.resize(15,0);
    player2.resize(0);
    player2.resize(15,0);
    player3.resize(0);
    player3.resize(15,0);
    player4.resize(0);
    player4.resize(15,0);
    table.resize(0);
    table.resize(15,0);
}

int trans(string c){
    if (c=="A")return 1;
    else if (c=="10")return 10;
    else if (c=="J")return 11;
    else if (c=="Q")return 12;
    else if (c=="K")return 13;
    else return c[0]-'0';
}

string revtrans(int n){
    if (n==10)return "10";
    if (n==11)return "J";
    if (n==12)return "Q";
    if (n==13)return "K";
    if (n==1)return "A";
    string s;
    s+=(char)(n-'0');
    return s;
}

void input(){
    player1.push_back(trans(c));
    for(int i=2;i<=13;i++){
        cin>>c;
        player1.push_back(trans(c));
    }
    for(int i=1;i<=13;i++){
        cin>>c;
        player2.push_back(trans(c));
    }
    for(int i=1;i<=13;i++){
        cin>>c;
        player3.push_back(trans(c));
    }
    for(int i=1;i<=13;i++){
        cin>>c;
        player4.push_back(trans(c));
    }
}


struct cheat{
    bool cheated(0);
    bool isempty(0);
    vi deploy(15);
    int statnum,statrank,nowplayer;
}

cheat startplayer1(int statement){
    cheat ret;
    ret.nowplayer=1;
    ret.statnum=1;
    if (player1[statement]){
        player1[statement]--;
        ret.statrank=statement;
        ret.deploy[statement]++;
        for (int i=1;i<=13;i++){
            ret.isempty|=player1[i];
        }
        ret.isempty=!ret.isempty;
        return ret;
    }
    else {
        ret.cheated=1;
        for (int i=statement;i<=13;i++){
            if (player1[i]){
                player1[i]--;
                ret.statrank=i;
                ret.deploy[i]++;
                for (int i=1;i<=13;i++){
                    ret.isempty|=player1[i];
                }
                ret.isempty=!ret.isempty;
                return ret;
            }
        }
        for (int i=1;i<statement;i++){
            if (player1[i]){
                player1[i]--;
                ret.statrank=i;
                ret.deploy[i]++;
                for (int i=1;i<=13;i++){
                    ret.isempty|=player1[i];
                }
                ret.isempty=!ret.isempty;
                return ret;
            }
        }
    }
}

cheat startplayer2(int statement){
    cheat ret;
    ret.nowplayer=2;
    if (player2[statement]){
        ret.statnum=player2[statement];
        player2[statement]=0;
        ret.statrank=statement;
        ret.deploy[statement]=ret.statnum;
        for (int i=1;i<=13;i++){
            ret.isempty|=player2[i];
        }
        ret.isempty=!ret.isempty;
        return ret;
    }
    else {
        ret.statnum=1;
        ret.cheated=1;
        for (int i=statement;i<=13;i++){
            if (player2[i]){
                player2[i]--;
                ret.statrank=i;
                ret.deploy[i]++;
                for (int i=1;i<=13;i++){
                    ret.isempty|=player2[i];
                }
                ret.isempty=!ret.isempty;
                return ret;
            }
        }
        for (int i=1;i<statement;i++){
            if (player2[i]){
                player2[i]--;
                ret.statrank=i;
                ret.deploy[i]++;
                for (int i=1;i<=13;i++){
                    ret.isempty|=player2[i];
                }
                ret.isempty=!ret.isempty;
                return ret;
            }
        }
    }
}

cheat startplayer3(int statement){
    cheat ret;
    ret.nowplayer=3;
    if (player3[statement]){
        ret.statnum=player3[statement];
        player3[statement]=0;
        ret.statrank=statement;
        ret.deploy[statement]=ret.statnum;
        for (int i=1;i<=13;i++){
            ret.isempty|=player3[i];
        }
        ret.isempty=!ret.isempty;
        return ret;
    }
    else {
        ret.cheated=1;
        for (int i=1;i<=13;i++){
            if (player3[i]){
                ret.statnum=player3[i];
                player3[i]=0;
                ret.statrank=i;
                ret.deploy[i]=ret.statnum;
                for (int i=1;i<=13;i++){
                    ret.isempty|=player3[i];
                }
                ret.isempty=!ret.isempty;
                return ret;
            }
        }
    }
}

cheat startplayer4(int statement){
    cheat ret;
    ret.nowplayer=4;
    if (player4[statement]>=3){
        ret.statnum=player4[statement];
        player4[statement]=0;
        ret.statrank=statement;
        ret.deploy[statement]=ret.statnum;
        for (int i=1;i<=13;i++){
            ret.isempty|=player4[i];
        }
        ret.isempty=!ret.isempty;
        return ret;
    }
    else {
        ret.statnum=player4[statement];
        player4[statement]=0;
        ret.statrank=statement;
        ret.deploy[statement]=ret.statnum;
        for (int i=1;i<=13;i++){
            if (player4[i]){
                ret.cheat=1;
                player4[i]--;
                ret.deploy[i]++;
                ret.statnum++;
                break;
            }
        }
        for (int i=1;i<=13;i++){
            ret.isempty|=player4[i];
        }
        ret.isempty=!ret.isempty;
        return ret;
    }
}

bool challenge1(cheat ch){
    if (ch.nowplayer==4){
        if (!player1[ch.statrank%13+1])return true;
    }
    if (ch.deploy[ch.statrank]+player1[ch.statrank]>4)return true;
    return false;
}
bool challenge2(cheat ch){
    if (ch.nowplayer==1){
        if (!player2[ch.statrank%13+1])return true;
    }
    return false;
}
bool challenge3(cheat ch){
    if (player3[ch.statrank]==4)return true;
    return false;
}
bool challenge4(cheat ch){
    if (ch.isempty)return true;
    else return false;
}

void jiesuan(vi&a,vi&b){
    for (int i=1;i<=13;i++){
        b[i]+=a[i];
    }
    a.resize(0);
    a.resize(15,0);
}

bool turn(int player,int statement){
    cheat nowstatement;
    if (player==1){
        nowstatement=startplayer1(statement);
        if (challenge2(nowstatement)){
            if (nowstatement.cheated){
                jiesuan(table,player1);
                jiesuan(nowstatement.deploy,player1);
            }
            else {
                jiesuan(table,player2);
                jiesuan(nowstatement.deploy,player2);
            }
        }
        else if (challenge3(nowstatement)){
            if (nowstatement.cheated){
                jiesuan(table,player1);
                jiesuan(nowstatement.deploy,player1);
            }
            else {
                jiesuan(table,player3);
                jiesuan(nowstatement.deploy,player3);
            }
        }
        else if (challenge4(nowstatement)){
            if (nowstatement.cheated){
                jiesuan(table,player1);
                jiesuan(nowstatement.deploy,player1);
            }
            else {
                jiesuan(table,player4);
                jiesuan(nowstatement.deploy,player4);
            }
        }
        else {
            jiesuan(nowstatement.deploy,table);
            if (nowstatement.isempty)return 1;//游戏结束
        }
    }
    else if (player==2){
        nowstatement=startplayer2(statement);
        if (challenge3(nowstatement)){
            if (nowstatement.cheated){
                jiesuan(table,player2);
                jiesuan(nowstatement.deploy,player2);
            }
            else {
                jiesuan(table,player3);
                jiesuan(nowstatement.deploy,player3);
            }
        }
        else if (challenge4(nowstatement)){
            if (nowstatement.cheated){
                jiesuan(table,player2);
                jiesuan(nowstatement.deploy,player2);
            }
            else {
                jiesuan(table,player4);
                jiesuan(nowstatement.deploy,player4);
            }
        }
        else if (challenge1(nowstatement)){
            if (nowstatement.cheated){
                jiesuan(table,player2);
                jiesuan(nowstatement.deploy,player2);
            }
            else {
                jiesuan(table,player1);
                jiesuan(nowstatement.deploy,player1);
            }
        }
        else {
            jiesuan(nowstatement.deploy,table);
            if (nowstatement.isempty)return 1;//游戏结束
        }
    }
    else if (player==3){
        nowstatement=startplayer3(statement);
        if (challenge4(nowstatement)){
            if (nowstatement.cheated){
                jiesuan(table,player3);
                jiesuan(nowstatement.deploy,player3);
            }
            else {
                jiesuan(table,player4);
                jiesuan(nowstatement.deploy,player4);
            }
        }
        else if (challenge1(nowstatement)){
            if (nowstatement.cheated){
                jiesuan(table,player3);
                jiesuan(nowstatement.deploy,player3);
            }
            else {
                jiesuan(table,player1);
                jiesuan(nowstatement.deploy,player1);
            }
        }
        else if (challenge2(nowstatement)){
            if (nowstatement.cheated){
                jiesuan(table,player3);
                jiesuan(nowstatement.deploy,player3);
            }
            else {
                jiesuan(table,player2);
                jiesuan(nowstatement.deploy,player2);
            }
        }
        else {
            jiesuan(nowstatement.deploy,table);
            if (nowstatement.isempty)return 1;//游戏结束
        }
    }
    else if (player==4){
        nowstatement=startplayer4(statement);
        if (challenge1(nowstatement)){
            if (nowstatement.cheated){
                jiesuan(table,player4);
                jiesuan(nowstatement.deploy,player4);
            }
            else {
                jiesuan(table,player1);
                jiesuan(nowstatement.deploy,player1);
            }
        }
        else if (challenge2(nowstatement)){
            if (nowstatement.cheated){
                jiesuan(table,player4);
                jiesuan(nowstatement.deploy,player4);
            }
            else {
                jiesuan(table,player2);
                jiesuan(nowstatement.deploy,player2);
            }
        }
        else if (challenge3(nowstatement)){
            if (nowstatement.cheated){
                jiesuan(table,player4);
                jiesuan(nowstatement.deploy,player4);
            }
            else {
                jiesuan(table,player3);
                jiesuan(nowstatement.deploy,player3);
            }
        }
        else {
            jiesuan(nowstatement.deploy,table);
            if (nowstatement.isempty)return 1;//游戏结束
        }
    }
}

void output(int n){
    if (nowplayer==n){
        cout<<"WINNER";
    }
    else if (n==1){
        for (int i=1;i<=13;i++){
            while (player1[i]){
                cout<<revtrans(i)<<' ';
                player1[i]--;
            }
        }
    }
    cour<<endl
}

int main(){
    while (cin>>c){
        init();
        input();
        nowstatement=1;
        nowplayer=1;
        while (true){
            if (turn(nowplayer,nowstatement))break;
            nowstatement=nowstatement%13+1;
            nowplayer=nowplayer%4+1;
        }
        for (int i=1;i<=4;i++){
            output(i);
        }
    }
}