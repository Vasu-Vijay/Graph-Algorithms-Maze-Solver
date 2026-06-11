class Solution {
public:

    //backtracking, what an elegance; state is important, keep going down and changing same data structure
    void backtrackRowAdd(unordered_set<int>& cols, unordered_set<int>& minus, unordered_set<int>& plus, vector<int>& board, int row, int n, vector<vector<int>>& answers) {
        //final row added, just save answer
        if(row==n) {
            answers.push_back(board);
            return;
        }
        for(int col=0; col<n; col++) {
            //pruning part
            if(cols.count(col)) {
                continue;
            }
            if(minus.count(row-col)) {
                continue;
            }
            if(plus.count(row+col)) {
                continue;
            }
            //add to state
            board.push_back(col);
            cols.insert(col);
            minus.insert(row-col);
            plus.insert(row+col);
            //add further rows(all possibilities) with given state
            backtrackRowAdd(cols, minus, plus, board, row+1, n, answers);
            //remove stuff back to move on to next possible row
            board.pop_back();
            cols.erase(col);
            minus.erase(row-col);
            plus.erase(row+col);
        }
        //nothing to do here
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int> cols, minus, plus;
        vector<int> board;
        vector<vector<int>> answers;
        backtrackRowAdd(cols, minus, plus, board, 0, n, answers);
        //convert into required format
        vector<vector<string>> str_ans;
        string str="";
        for(int i=0; i<answers.size(); i++) {
            str_ans.push_back({});
            for(int j=0; j<n; j++) {
                for(int k=0; k<n; k++) {
                    str+=(k==answers[i][j])? "Q":".";
                }
                str_ans.back().push_back(str);
                str="";
            }
        }
        return str_ans;
    }
};