#include <bits/stdc++.h>
using namespace std;


#define MAXN 200005
#define INF 0x3fffffff

int A[MAXN];         //操作的序列,记得为（1...n）非（0...n）
//int max;
//int min;

typedef struct node
{
    int left;
    int right;
    int max;           //维护最大值
    int min;           //维护最小值
}node;

typedef node xdtree[MAXN<<2];        //存储线段树




void maintain(int root,xdtree &tree)         //向上调整，使得让线段树维护区间最小值最大值区间和
{
    int LC = root<<1;       //此根的左孩子
    int RC = (root<<1)+1;       //此根的右孩子
    tree[root].max = max(tree[LC].max,tree[RC].max);        //根的最大值
    tree[root].min = min(tree[LC].min,tree[RC].min);        //根的最小值
}


void Build(int root,int start,int end,xdtree &tree)                     //构建线段树
{                                                           //初始化时传入Build(1,1,n);
    tree[root].left = start;            //建区间大小
    tree[root].right = end;
    if(start == end)                    //当到达叶子节点时
    {
        tree[root].max = A[start];
        tree[root].min = A[start];
        return;
    }
    int mid = (start + end)>>1;         //中间分开
    Build(root<<1,start,mid,tree);           //对左孩子建树，左边孩子的编号为root*2
    Build((root<<1)+1,mid+1,end,tree);       //对右边孩子建树
    maintain(root,tree);
}


void update(int root,int pos,int value,xdtree &tree)                     //更新点的值
{
    if(tree[root].left == tree[root].right && tree[root].left == pos)   //更新叶子节点的值
    {
        tree[root].max = value;
        tree[root].min = value;
        return;
    }
    int mid = (tree[root].left + tree[root].right)>>1;          //中间分开成两个区间
    if(pos <= mid)                                       //更新的值在左孩子
        update(root<<1,pos,value,tree);                          //更新左孩子
    else
        update((root<<1)+1,pos,value,tree);                  //更新的值在右孩子
    maintain(root,tree);                                 //叶子节点更新完成后，会回溯到他的父节点，这样一直往上更新到根节点，维护线段树性质
}

int RminQ(int root,int start,int end,xdtree &tree)              //查询区间最小值
{
    if(start == tree[root].left && tree[root].right == end)             //正好匹配区间
    {
        return tree[root].min;
    }
    int mid = (tree[root].left + tree[root].right)>>1;                  //区间分开，去查左右孩子
    int ret = INF;                                             //先把结果记录为很大
    if(end <= mid)                                          //  完全左区间匹配
        ret = min(ret,RminQ(root<<1,start,end,tree));
    else if(start >= mid+1)                                 //完全右区间匹配
        ret = min(ret,RminQ((root<<1)+1,start,end,tree));
    else
    {
        int a = RminQ(root<<1,start,mid,tree);
        int b = RminQ((root<<1)+1,mid+1,end,tree);
        ret = min(a,b);                                     //求左右区间和匹配区间相符的最小值的较小值
    }
    return ret;                             //记得要返回本次查询的结果
}


int RmaxQ(int root,int start,int end,xdtree &tree)                 //查询区间最大值
{
    if(start == tree[root].left && tree[root].right == end)
    {
        return tree[root].max;
    }
    int mid = (tree[root].left + tree[root].right)>>1;
    int ret = -INF;                                        //************可能是 （-INF）要尽可能的小
    if(end <= mid)
        ret = max(ret,RmaxQ(root<<1,start,end,tree));        //完全左孩子区间匹配
    else if(start >= mid+1)
        ret = max(ret,RmaxQ((root<<1)+1,start,end,tree));        //完全右孩子区间匹配
    else
    {
        int a = RmaxQ(root<<1,start,mid,tree);
        int b = RmaxQ((root<<1)+1,mid+1,end,tree);
        ret = max(a,b);                                 //求的左右两个区间和匹配区间相符的最大值得较大者
    }
    return ret;                             //记得返回结果
}

xdtree tree[32];

int input[200005][6];
int temp[6];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        for (int j=0;j<k;j++)
            cin>>input[i][j];
    }
    
    
    for (int i=0;i<(1<<k);i++){
        for (int j=1;j<=n;j++){
            A[j]=0;
            for (int ii=0;ii<k;ii++){
                if ((1<<ii)&i){
                    A[j]+=input[j][ii];
                }
                else A[j]-=input[j][ii];
            }
            //cout<<A[j]<<' ';
        }
        //cout<<endl;
        Build(1,1,n,tree[i]);
    }
    
    
    int q;
    cin>>q;
    for (int i=1;i<=q;i++){
        int pd;
        cin>>pd;
        if (pd==1){
            int changed;
            cin>>changed;
            for (int i=0;i<k;i++){
                cin>>temp[i];
            }
            for (int i=0;i<(1<<k);i++){
                int orz=0;
                for (int ii=0;ii<k;ii++){
                    if ((1<<ii)&i){
                        orz+=temp[ii];
                    }
                    else orz-=temp[ii];
                }
                //cout<<orz<<' ';
                update(1,changed,orz,tree[i]);
            }
            //puts("");
        }
        
        else {
            int l,r;
            cin>>l>>r;
            int ans=0;
            for (int i=0;i<(1<<k);i++){
                //cout<<RmaxQ(1,l,r,tree[i])<<' '<<RminQ(1,l,r,tree[i])<<endl;
                ans=max(ans,RmaxQ(1,l,r,tree[i])-RminQ(1,l,r,tree[i]));
            }
            cout<<ans<<"\n";
        }
    }
}