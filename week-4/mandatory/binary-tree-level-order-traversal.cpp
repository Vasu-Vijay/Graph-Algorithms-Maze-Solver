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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) {return ans;}
        
        queue<TreeNode*> q;
        TreeNode* x;
        q.push(root);
        q.push(nullptr);
        ans.push_back({root->val});
        ans.push_back({});
        while(1) {
            x=q.front();
            q.pop();
            if(q.empty()) {
                break;
            }
            if(x==nullptr) {
                q.push(nullptr);
                ans.push_back({});
            } else {
                if(x->left) {
                    q.push(x->left);
                    ans.back().push_back(x->left->val);
                }
                if(x->right) {
                    q.push(x->right);
                    ans.back().push_back(x->right->val);
                }
            }
        }
        if(ans.size() > 0 && ans.back().size() == 0) {
            ans.pop_back();
        }
        return ans;
    }
};