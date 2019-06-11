#include <bits/stdc++.h>
using namespace std;

char input[1000];

struct node{
    node* tree[256]={0};
};

void buildtree(const char *s,node* &root){
    if (s[0]==0){
        return;
    }
    if (root==0){
        root=(node*)malloc(sizeof(node));
        memset(root,0,sizeof(node));
    }
    buildtree(s+1,root->tree[*s]);
}
int main(){
    node *root=0;
    string s;
    cin>>s;
    string d;
    int k=5;
    while (k--){
        cin>>d;
        d+='\1';
        buildtree(d.c_str(),root);
    }
    queue<node*> vec;
    vec.push(root);
    for (auto i:s){
        int flag = 1;
        int num=vec.size();
        while (num--){
            node *now=vec.front();
            vec.pop();
            if (now->tree[1]!=0&&flag){
                vec.push(root);
                flag=0;
            }
            if (now->tree[i]!=0){
                vec.push(now->tree[i]);
            }
        }
    }
    while (!vec.empty()){
        if (vec.front()==root){
            cout<<"True"<<endl;
            return 0;
        }
        vec.pop();
    }
    cout<<"False"<<endl;
    
}