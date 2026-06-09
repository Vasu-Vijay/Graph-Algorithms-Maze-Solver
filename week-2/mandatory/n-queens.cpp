class Solution {
public:
    vector<vector<int>> answer(int n) {
        if(n==1) {
            return {{0}};
        }
        auto smaller = answer(n-1);
        int size=smaller.size();
        vector<vector<int>> ans;
        for(int i=0; i<size; i++) { //loop over all configs
            for(int j=0; j<=n-1; j++) { //where to insert the new queen
                //check if this posn okay
                unordered_set<int> checkset1, checkset2;
                bool ok=true;
                //check for duplicate i-j's, i+j's for diagnoal
                for(int k=0; k<n; k++) {
                    int y;
                    if(k==j) {y=n-1;} 
                    else if(k>j) {y=smaller[i][k-1];} 
                    else {y=smaller[i][k];}
                    int iminusj = k-y;
                    if(checkset1.count(iminusj)) {
                        ok=false;
                        break;
                    }
                    checkset1.insert(iminusj);
                    int iplusj = k+y;
                    if(checkset2.count(iplusj)) {
                        ok =false;
                        break;
                    }
                    checkset2.insert(iplusj);
                }
                if(!ok) continue;

                vector<int> oneans = smaller[i];
                if(j==n-1) {
                    oneans.push_back(n-1);
                } else {
                    oneans.insert(oneans.begin()+j, n-1);
                }
                ans.push_back(oneans);
            }
        }

        return ans;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> compressed = answer(n);
        vector<vector<string>> ans;
        for(int i=0; i<compressed.size(); i++) {
            ans.push_back({});
            for(int j=0; j<n; j++) {
                ans.back().push_back("");
                for(int k=0; k<n ; k++) {
                    ans.back().back()+= k==compressed[i][j]?"Q":".";
                }
            }
        }
        return ans;
    }
};