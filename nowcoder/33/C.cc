#include <bits/stdc++.h>
using namespace std;

bool cmp(char x,char y){
    return x>y;
}

int cnt[11],cmt[11];

string s,num[10][105],q1,q2;

int main(){
    int T;
    q1="0";
    for(int i=0;i<10;i++){
        q1[0]=i+'0';num[i][0]="";
        for(int j=1;j<=100;j++)
            num[i][j]=num[i][j-1]+q1;
    }
    cin>>T;
    while(T--){
        cin>>s;
        int slen=s.length();
        if(slen<3){
            if(slen==1){
                if((s[0]-'0')%8==0){
                    cout<<s<<endl;
                }else cout<<"-1"<<endl;
            }else{
                int g=(s[1]-'0')*10+s[0]-'0';
                int t=(s[0]-'0')*10+s[1]-'0';
                int res=-1;
                if(g%8==0){
                    res=max(res,g);
                }
                if(t%8==0){
                    res=max(res,t);
                }
                cout<<res<<endl;
            }
            continue;
        }
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<slen;i++){
            cnt[s[i]-'0']++;
        }
        string res;
        bool finded=0;
        q2="000";
        for(int i=0;i<1000;i+=8){
            memset(cmt,0,sizeof(cmt));
            q1="";
            int g=i;
            for(int j=0;j<3;j++){
                cmt[g%10]++;
                q2[2-j]=g%10+'0';
                g/=10;
            }
            int flag=1;
            for(int j=0;j<10;j++){
                if(cmt[j]>cnt[j]){flag=0;break;}
            }
            if(!flag)continue;
            for(int j=9;j>=0;j--){
                q1+=num[j][cnt[j]-cmt[j]];
            }
            q1+=q2;
            if(finded){
                if(res<q1)
                    res=q1;
            }else {
                res=q1;
                finded=1;
            }
        }
        if(finded)
            cout<<res<<endl;
        else cout<<"-1"<<endl;
    }
}