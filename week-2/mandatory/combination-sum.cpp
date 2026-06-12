class Solution {
public:
    void backTrackAddNum(int start_idx, int sum, int target, vector<int>& ans, vector<vector<int>>& answers, vector<int> &candidates) {
        if(sum == target) {
            answers.push_back(ans);
            return;
        }
        for(int i=start_idx; i<candidates.size(); i++) {
            if(candidates[i] > target - sum) {
                continue;
            }
            ans.push_back(candidates[i]);
            backTrackAddNum(i, sum + candidates[i], target, ans, answers, candidates);
            ans.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answers;
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        backTrackAddNum(0, 0, target, ans, answers, candidates);
        return answers;
    }
};