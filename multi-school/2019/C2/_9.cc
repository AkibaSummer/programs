#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
char str[maxn];      //原字符串
char tmp[maxn << 1]; //转换后的字符串
int Len[maxn << 1];
//转换原始串
int INIT(const char *st)
{
    int i, len = strlen(st);
    tmp[0] = '@'; //字符串开头增加一个特殊字符，防止越界
    for (i = 1; i <= 2 * len; i += 2)
    {
        tmp[i] = '#';
        tmp[i + 1] = st[i / 2];
    }
    tmp[2 * len + 1] = '#';
    tmp[2 * len + 2] = '$'; //字符串结尾加一个字符，防止越界
    tmp[2 * len + 3] = 0;
    return 2 * len + 1; //返回转换字符串的长度
}
//Manacher算法计算过程
int MANACHER(char *st)
{
    int len = strlen(st);
    int mx = 0, ans = 0, po = 0; //mx即为当前计算回文串最右边字符的最大值
    for (int i = 1; i < len; i++)
    {
        if (mx > i)
            Len[i] = min(mx - i, Len[2 * po - i]); //在Len[j]和mx-i中取个小
        else
            Len[i] = 1; //如果i>=mx，要从头开始匹配
        while (st[i - Len[i]] == st[i + Len[i]])
            Len[i]++;
        if (Len[i] + i > mx) //若新计算的回文串右端点位置大于mx，要更新po和mx的值
        {
            mx = Len[i] + i;
            po = i;
        }
        ans = max(ans, Len[i]);
    }
    return ans - 1; //返回Len[i]中的最大值-1即为原串的最长回文子串额长度
}

priority_queue<pair<int,int>> que[maxn<<1];
int ans_plus[maxn];
int ans_sub[maxn];

void merge(priority_queue<pair<int,int>> &merged){
    pair<int,int> temp;
    priority_queue<pair<int,int>> ret;
    while (!merged.empty()){
        temp=merged.top();
        merged.pop();
        while (!merged.empty()&&temp.first<=merged.top().second+1){
            temp.first=min(temp.first,merged.top().first);
            temp.second=max(temp.second ,merged.top().second);
            merged.pop();
        }
        ret.push(temp);
    }
    swap(ret,merged);
}

int main()
{
    string s;
    cin >> s;
    INIT(s.c_str());
    int n = s.length(), m = strlen(tmp);
    MANACHER(tmp);
    // for (int i=1;i<=m-2;i++){
    //     cout<<Len[i]<<' ';
    // }
    for (int i=1;i<=m-2;i++){
        if (Len[i]>1){
            if (Len[i]+i-1<=m-2){
                que[i+Len[i]-1].push({Len[i],Len[i]});
            }
            else {
                que[m-2].push({m-2-i+1,m-2-i+1});
            }
        }
    }
    ans_plus[1]=n;
    ans_sub[1]=n;
    for (int i=m-2;i>=1;i--){
        merge(que[i]);
        pair<int,int> temp;
        while (!que[i].empty()){
            temp=que[i].top();
            que[i].pop();
            temp={max(temp.first,2),temp.second};
            if (temp.second>=2){
                if (temp.second>=3)
                    que[i-1].push({max(temp.first-1,2),temp.second-1});
                if ((Len[i]+1)/2<temp.first){
                    continue;
                }
                else {
//                    if ((temp.first*2-1)-1==2)cout<<i<<endl;
                    ans_plus[(temp.first*2-1)-(i%2)]++;
                    ans_sub[min(temp.second,(Len[i]+1)/2)*2-1-(i%2)]++;
                }
            }
        }
    }
    int temp = 0;
    for (int i=1;i<=n;i++){
        temp+=ans_plus[i];
        cout<<temp<< ' ';
        temp-=ans_sub[i];
    }
}