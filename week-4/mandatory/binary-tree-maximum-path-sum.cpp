/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPath(TreeNode* root, int& ans) {
        if(root==nullptr) {
            return 0;
        }
        int lpath = maxPath(root->left, ans);
        int rpath = maxPath(root->right, ans);
        ans = max(ans, max(lpath,0) + max(rpath,0) + root->val);
        return max(max(lpath, rpath),0) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        maxPath(root, ans);
        return ans;
    }
};