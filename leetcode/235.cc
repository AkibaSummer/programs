//二叉树 O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL)return NULL;
        else if (root==p)return p;
        else if (root==q)return q;
        else { 
            TreeNode* l(lowestCommonAncestor(root->left,p,q)),*r(lowestCommonAncestor(root->right,p,q));
            if (l==NULL)return r;
            else if (r==NULL)return l;
            else return root;
        }
    }
};

//二叉搜索树 O(log(n))
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return root==NULL?NULL:(root->val<p->val&&root->val<q->val?lowestCommonAncestor(root->right,p,q):(root->val>p->val&&root->val>q->val?lowestCommonAncestor(root->left,p,q):root));
        
    }
};