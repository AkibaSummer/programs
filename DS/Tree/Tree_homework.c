#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#define max(a,b) ((a)>(b)?(a):(b))
typedef int DataType;

typedef struct TreeNode {
    DataType data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

int leafNumber(TreeNode* root){
    //printf ("leafNumber_data:%d\n",root->data);
    if (root->left==NULL&&root->right==NULL) return 1;
    else if (root==NULL) return 0;
    else return leafNumber(root->left)+leafNumber(root->right);
}

int maxDepth(TreeNode* root) {
    return root==NULL?0:(max(maxDepth(root->left),maxDepth(root->right))+1);  
}

TreeNode* buildTree(DataType Preorder[],DataType Inorder[],int number){
    //printf("number:%d,data:%d\n",number,Preorder[0]);
    if (number==0) return NULL;
    else if (number==1){
        TreeNode* ret = (TreeNode*)malloc(sizeof(TreeNode));
        ret->data=Preorder[0];
        ret->left=ret->right=NULL;
        return ret;
    }
    else {
        TreeNode* ret = (TreeNode*)malloc(sizeof(TreeNode));
        ret->data=Preorder[0];
        for (int i=0;i<number;i++){
            if (Inorder[i]==Preorder[0]){
                ret->left=buildTree(Preorder+1,Inorder,i);
                ret->right=buildTree(Preorder+1+i,Inorder+i+1,number-i-1);
                return ret;
            }
        }
    }
}
/********
    3
   / \
  9  20
    /  \
   15   7
********/
int main(){
    DataType Preorder[5]={3,9,20,15,7};
    DataType Inorder [5]={9,3,15,20,7};
    TreeNode* root=buildTree(Preorder,Inorder,5);
    printf("叶子节点数目为： %d \n",leafNumber(root));
    printf("最大深度为： %d \n",maxDepth(root));
}