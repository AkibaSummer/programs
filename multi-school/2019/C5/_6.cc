#include <bits/stdc++.h>
using namespace std;
int next1[100005],ans[100005];
void getnext(string str)
{
    next1[0]=-1;
    int k=-1,j=0;
    while(j<str.size()-1){
        if(k==-1||str[k]==str[j]){
            k++;j++;
            next1[j]=k;
        }
        else{
            k=next1[k];
        }
    }
}
int main()
{
    string str2;
    cin>>str2;
    str2=str2+'_';
    getnext(str2);
    for(int i=1;i<str2.size();i++)
        cout<<next1[i]<<' ';
    next1[0]=0;
    puts("");
    ans[1]=0;
    for (int i=2;i<str2.size();i++){
        if (next1[i]==0)ans[i]=ans[i-1]+1+(next1[i-1]>next1[i]);
        else {
            ans[i]=next1[i]+ans[i-next1[i]]+ans[next1[i]]+(next1[i]!=next1[i-1]+1);
        }
        cout<<ans[i]<<" ";
    }
    puts("");
    cout<<ans[str2.size()-1]<<endl;
    return 0;
}