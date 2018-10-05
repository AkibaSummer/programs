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
    vector<int>ret;
    void getAns(TreeNode *root){
        if (root==NULL)return ;
        else {
            getAns(root->left);
            getAns(root->right);
            ret.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        getAns(root);
        return ret;
    }
};