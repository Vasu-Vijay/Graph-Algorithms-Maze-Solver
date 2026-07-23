class Solution {
public:
    int findparent(int node, vector<int>& parent) {
        if(parent[node] == node) {
            return node;
        }
        return parent[node] = findparent(parent[node], parent);
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);

        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        unordered_map<string, int> emailidx;

        for(int i=0; i<n; i++) {
            for(int j=1; j<accounts[i].size(); j++) {
                string email = accounts[i][j];

                if(emailidx.count(email)) {
                    int parent1 = findparent(i, parent);
                    int parent2 = findparent(emailidx[email], parent);
                    parent[parent1] = parent2;
                } else {
                    emailidx[email] = i;
                }
            }
        }

        unordered_map<int, vector<string>> groups;

        for(auto it: emailidx) {
            string email = it.first;
            int idx = it.second;
            int parentidx = findparent(idx, parent);
            groups[parentidx].push_back(email);
        }

        vector<vector<string>> ans;

        for(auto it: groups) {
            int idx = it.first;
            vector<string> curr;
            curr.push_back(accounts[idx][0]);

            vector<string> emails = it.second;
            sort(emails.begin(), emails.end());

            for(int i=0; i<emails.size(); i++) {
                curr.push_back(emails[i]);
            }

            ans.push_back(curr);
        }

        return ans;
    }
};