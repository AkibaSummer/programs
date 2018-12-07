#include <bits/stdc++.h>
using namespace std;
char s[100005];
unsigned long long hashA[26][100005],hashB[100005];
unsigned long long gethash(unsigned long long *Hash,int x, int len){
    return Hash[x + len - 1] - Hash[x - 1] * hashB[len];
}
int main(){
    int n,q,slen;
    scanf("%d%s%d",&n,s+1,&q);
    int x,y,l;
    slen=strlen(s+1);
    hashB[0]=1;
    for(int i=1;i<=slen;i++){
        for(int j=0;j<26;j++)hashA[j][i]=hashA[j][i-1]*259+(s[i]-'a'+j)%26+'a';
        hashB[i]=hashB[i-1]*259;
    }
    while(q--){
        scanf("%d%d%d",&x,&y,&l);
        unsigned long long hx,hy=gethash(hashA[0],y,l);
        int res=-1;
        for(int j=0;j<26;j++){
            hx=gethash(hashA[j],x,l);
            if(hx==hy){
                res=j;
                break;
            }
        }
        printf("%d\n",min(res,26-res));
    }
}