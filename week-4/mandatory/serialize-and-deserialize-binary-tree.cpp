/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void convert(TreeNode* root, vector<TreeNode*>& vect) {
    vect.push_back(root); //1 2 null null 3 4 null null 5 null null
    if(root==nullptr) {
        return;
    }
    convert(root->left, vect);
    convert(root->right, vect);
}

TreeNode* generate(vector<int>& vals, unordered_set<int>& null_idx, int& idx) {
    if(null_idx.count(idx)) {
        idx++;
        return nullptr;
    }
    TreeNode* root = new TreeNode(vals[idx]);
    idx++;
    root->left = generate(vals, null_idx, idx);
    root->right = generate(vals, null_idx, idx);

    return root;
}

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<TreeNode*> vect;
        convert(root, vect);
        string str = "";
        for(int i=0; i<vect.size(); i++) {
            if(vect[i] == nullptr) {
                str+="null";
            } else {
                str += to_string(vect[i]->val);
            }
            str += ",";
        }
        // cout<<str<<endl;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string num="";
        vector<int> vals;
        unordered_set<int> null_idx;
        int idx=0;
        for(int i=0; i<data.size(); i++) {
            if(data[i] == ',') {
                if(num == "null") {
                    null_idx.insert(idx);
                    idx++;
                    vals.push_back(-1);
                    num = "";
                } else {
                    // cout<<"num: "<<num<<endl;
                    vals.push_back(stoi(num));
                    idx++;
                    num = "";
                }
            } else {
                num += data[i];
                // cout<<"adding "<<data[i]<<" to make num = "<<num<<endl;
            }
        }
        for(int i=0; i<vals.size(); i++) {
            // cout<<vals[i]<<" ";
        }
        // cout<<endl;
        idx=0;
        return generate(vals, null_idx, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));