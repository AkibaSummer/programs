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
    pair<double,double> getans(TreeNode* root){
        if (root->left==NULL&&root->right==NULL){
            return {root->val,0};
        }
        else if (root->left==NULL){
            auto right=getans(root->right);
            return {right.first+root->val,right.second};
        }
        else if (root->right==NULL){
            auto left=getans(root->left);
            return {left.first+root->val,left.second};
        }
        else {
            auto right=getans(root->right);
            auto left=getans(root->left);
            auto r1=right.first,r2=right.second;
            auto l1=left.first,l2=left.second;
            if (r1>=l1){
                if (r1-l1<=l2*2){
                    return {root->val,r2+l2-(r1-l1)/2+r1};
                }
                else {
                    return {r1-l1-l2*2+root->val,r2+l2*2+l1};
                }
            }
            else {
                if (l1-r1<=r2*2){
                    return {root->val,l2+r2-(l1-r1)/2+l1};
                }
                else {
                    return {l1-r1-r2*2+root->val,l2+r2*2+r1};
                }                
            }
            // return {max(r1,l1)-min(r1,l1)+root->val,r2+l2+min(r1,l1)};
        }
    }
    
    double minimalExecTime(TreeNode* root) {
        auto ans = getans(root);
        auto a1=ans.first,a2=ans.second;
        return a1+a2;
                
    }
};