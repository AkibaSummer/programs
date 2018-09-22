//8ms
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
private:
    pair<int,int> getans(TreeNode* root){
        pair<int,int> l({0,0}),r({0,0});
        if (root->left!=nullptr)l=getans(root->left);
        if (root->right!=nullptr)r=getans(root->right);
        //cout<<root->val<<endl;
        return {l.second+r.second+root->val,
                max(l.first,l.second)+max(r.first,r.second)};
    }
public:
    int rob(TreeNode* root) {
        if (root==nullptr) return 0;
        pair<int,int> ret(getans(root));
        return max(ret.first,ret.second);
    }
};