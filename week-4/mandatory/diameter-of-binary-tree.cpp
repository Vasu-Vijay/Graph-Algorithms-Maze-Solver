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
    int getAns(int& ans, TreeNode* root) {
        int maxlen_left=-1, maxlen_right=-1;
        if(root->left) {
            maxlen_left = getAns(ans, root->left);
        }
        if(root->right) {
            maxlen_right = getAns(ans, root->right);
        }
        ans = max(ans, maxlen_left+maxlen_right+2);
        return max(maxlen_right, maxlen_left)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        getAns(ans, root);
        return ans;
    }
};