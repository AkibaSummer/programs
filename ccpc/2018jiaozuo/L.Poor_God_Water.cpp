#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
const int maxn=20;
typedef long long ll;
ll tmp[maxn][maxn];
void multi(ll a[][maxn],ll b[][maxn],int N)//暴力计算矩阵乘法,N为矩阵大小
{
    memset(tmp,0,sizeof tmp);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            for(int k=1;k<=N;k++)
                tmp[i][j]+=a[i][k]*b[k][j]%mod,tmp[i][j]%=mod;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            a[i][j]=tmp[i][j];
}
ll res[maxn][maxn];
void Pow(ll a[][maxn],ll n,int N)////n是幂，N是矩阵大小
{
    memset(res,0,sizeof res);
    for(int i=1;i<=N;i++) res[i][i]=1;//01矩阵
    while(n)
    {
        if(n&1)
            multi(res,a,N);//res=res*a;复制直接在multi里面实现了；
        multi(a,a,N);//a=a*a
        n>>=1;
    }
}
int main()
{
    long long n,i,j;ll matrci[maxn][maxn],k;
    //cin>>n>>k;//n为矩阵大小,k为幂次
    int t;
    cin>>t;
    while(t--){
        for(i=1;i<=9;i++)
            for(j=1;j<=9;j++)
                matrci[i][j]=0;
        matrci[1][4]=matrci[1][7]=matrci[2][1]=matrci[2][4]=matrci[2][7]=matrci[3][4]=matrci[3][1]=1;
        matrci[4][2]=matrci[4][5]=matrci[4][8]=matrci[5][2]=matrci[5][8]=matrci[6][2]=matrci[6][5]=1;
        matrci[7][3]=matrci[7][9]=matrci[8][6]=matrci[8][9]=matrci[9][3]=matrci[9][6]=1;
        cin>>n;
        if(n==1){
            cout<<3<<'\n';
        }
        else if(n==2){
            cout<<9<<'\n';
        }
        else{
            Pow(matrci,n-2,9);
            ll ans=0;
            for(i=1;i<=9;i++) {
                for (j = 1; j <= 9; j++) {
                    //cout << matrci[i][j] << ' ';
                    ans = (ans + res[i][j]) % mod;
                }
               // cout<<endl;
            }
                cout<<ans<<'\n';

        }
    }

    return 0;
}