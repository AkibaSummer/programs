#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> getarray(const char s[],const char *end){
    vector<pair<int,int>> ret;
    vector<int> insn;
    // cout<<233<<endl;
    for (int i=0;s+i<end;i++){
        // cout<<s[i];
        if (s[i]=='s'){
            int st=i;
            if (insn.size()){
                for (auto i:insn)ret.push_back({1,i});
                insn.clear();
            }
            i++;
            int type=0;
            if (s[i]=='o')type=1;
            int num=0;
            vector<int> ins;
            for (;s+i<end;i++){
                if (s[i]=='('||s[i]=='[')num++;
                else if (s[i]==')'||s[i]==']')num--;
                if (s[i]==')'&&num==0)break;
                if (s[i]>='0'&&s[i]<='9'){
                    int k=s[i]-'0';
                    i++;
                    while(s[i]>='0'&&s[i]<='9'){
                        k=k*10+s[i]-'0';
                        i++;
                    }
                    ins.push_back(k);
                    i--;
                }
            }
            sort(ins.begin(),ins.end());
            if (ins[0]==ins[ins.size()-1])type=1;
            for (auto i:ins){
                ret.push_back({type==0?-ins.size():type,i});
            }
        }
        else {
            if (s[i]>='0'&&s[i]<='9'){
                int k=s[i]-'0';
                i++;
                while(s[i]>='0'&&s[i]<='9'){
                    k=k*10+s[i]-'0';
                    i++;
                }
                insn.push_back(k);
                i--;
            }
        }
    }
    if (insn.size()){
        for (auto i:insn)ret.push_back({1,i});
        insn.clear();
    }
    return ret;
}

int main(){
    string a;
    string b;
    cin>>a;
    cin>>b;
    vector<pair<int,int>> aa,bb;
    aa=getarray(a.c_str(),a.c_str()+a.size()),bb=getarray(b.c_str(),b.c_str()+b.size());
    // for (auto i:aa)cout<<i.first<<' '<<i.second<<endl;
    // for (auto i:bb)cout<<i.first<<' '<<i.second<<endl;
    if (aa.size()!=bb.size())puts("not equal");
    else {
        for (int i=0;i<aa.size();i++){
            if (aa[i]!=bb[i]){
                puts("not equal");
                return 0;
            }
        }
        puts("equal");
    }
}