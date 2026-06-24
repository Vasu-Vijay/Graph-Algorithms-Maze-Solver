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
    void generateAns(vector<int>& ans, TreeNode* root) {
        if(!root) { return; }

        if(root->left)
            generateAns(ans, root->left);

        ans.push_back(root->val);

        if(root->right)
            generateAns(ans, root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        generateAns(ans, root);
        return ans;
    }
};