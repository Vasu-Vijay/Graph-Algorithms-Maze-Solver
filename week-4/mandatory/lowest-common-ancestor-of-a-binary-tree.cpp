/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool pfound = false, qfound = false;
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) {
            return nullptr;
        }
        
        TreeNode* lcaL = lowestCommonAncestor(root->left, p, q);
        TreeNode* lcaR = lowestCommonAncestor(root->right, p, q);
        if(lcaL) {
            return lcaL;
        } else if(lcaR) {
            return lcaR;
        } else if(pfound && qfound) {
            return root;
        }
        pfound = pfound || p==root;
        qfound = qfound || q==root;
        return nullptr;
    }
};