#include <bits/stdc++.h>
using namespace std;

int fd[10][10][10];

int main(){
    memset(fd,-1,sizeof(fd));
    int tot=100;
        for (int i=0;i<=9;i++){
            for (int j=0;j<=9;j++){
                fd[i][j][i]=1;
                fd[i][j][j]=1;
                // fd[i][j][0]=0;
            }
        }
    while(tot--){
        for (int i=0;i<=9;i++){
            for (int j=0;j<=9;j++){
                for (int k=0;k<=9;k++){
                    if (fd[i][j][k]!=-1){
                        if (fd[i][j][(k+i)%10]==-1)fd[i][j][(k+i)%10]=fd[i][j][k]+1;
                        else fd[i][j][(k+i)%10]=min(fd[i][j][(k+i)%10],fd[i][j][k]+1);
                        if (fd[i][j][(k+j)%10]==-1)fd[i][j][(k+j)%10]=fd[i][j][k]+1;
                        else fd[i][j][(k+j)%10]=min(fd[i][j][(k+j)%10],fd[i][j][k]+1);
                    }
                }
            }
        }
    }
    string s;
    cin>>s;
    // for (int k=1;k<s.size();k++)
                // cout<<(s[k]+10-s[k-1])%10<<endl;
    for (int i=0;i<=9;i++){
        for (int j=0;j<=9;j++){
            int flag = 1,ans=0;
            for (int k=1;k<s.size();k++){
                if (fd[i][j][(s[k]+10-s[k-1])%10]==-1){
                    flag = 0;
                    break;
                }
                else {
                    ans+=fd[i][j][(s[k]+10-s[k-1])%10]-1;
                }
            }
            if (flag)cout<<ans<<' ';
            else cout<<-1<<' ';
        }
        cout<<endl;
    }
}