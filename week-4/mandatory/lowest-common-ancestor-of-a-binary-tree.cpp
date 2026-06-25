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
    pair<bool, bool> lca(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans) {
        if(!root) {
            return {0,0};
        }
        pair<bool, bool> foundleft = lca(root->left, p, q, ans);
        pair<bool, bool> foundright = lca(root->right, p, q, ans);
        if(ans) {
            return {1,1};
        }
        if((foundleft.first || foundright.first || root == p) && (foundleft.second || foundright.second || root == q)) {
            ans = root;
        }
        return {foundleft.first || foundright.first || root==p, foundleft.second || foundright.second || root==q};
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=nullptr;
        lca(root, p, q, ans);
        return ans;
    }
};