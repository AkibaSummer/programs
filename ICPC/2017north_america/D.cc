#include<bits/stdc++.h>
using namespace std;
int can(string s)
{
    int res=0;bool isfu=false;
    for(auto a:s){
        if(a=='-')isfu=true;
        else res=res*10+(a-'0');
    }
    if(isfu)res=-res;
    return res;
}
int main()
{
    int i,j,k,n;string str,s;
    cin>>n>>k;
    getline(cin,str);
    getline(cin,str);
    stringstream command(str);
    vector<int>cc;
    while(command>>s){
        if(s=="undo"){
            command>>s;
            int qx=can(s);
            while(!cc.empty()&&qx){
                qx--;cc.pop_back();
            }
        }
        else{
            cc.push_back(can(s));
        }
    }
    int sum=0;
    for(auto a:cc)sum+=a;
    sum+=(int)1e6*n;
    cout<<sum%n<<endl;

    return 0;
}
/*
5 4
8 -2 3 undo 2
5 10
7 -3 undo 1 4 3 -9 5 undo 2 undo 1 6
*/