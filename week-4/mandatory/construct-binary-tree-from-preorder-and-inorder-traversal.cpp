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
    TreeNode* makeTree(vector<int>& preorder, vector<int>& inorder, int inL, int inR, int& pre) {
        TreeNode* root = new TreeNode();
        if(inL==inR-1) {
            root->val = inorder[inL];
            pre=pre+1;
            return root;
        }
        if(inL==inR) {
            return nullptr;
        }
        root->val = preorder[pre];
        int i;
        for(i=inL; i<inR; i++) {
            if(inorder[i] == root->val) {
                break;
            }
        }
        pre=pre+1;
        root->left = makeTree(preorder, inorder, inL, i, pre);
        // pre=pre+1;
        root->right = makeTree(preorder, inorder, i+1, inR, pre);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre=0;
        return makeTree(preorder, inorder, 0, preorder.size(), pre);
    }
};