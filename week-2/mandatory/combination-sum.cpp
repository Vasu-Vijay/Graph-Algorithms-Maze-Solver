#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    void getAns(unordered_map<int, vector<vector<int>>>& answers,
                vector<vector<int>> curanswers, vector<int> cursum,
                vector<int>& candidates, int target, int ogtarget) {
        if (answers.count(target)) {
            for (int i = 0; i < answers[target].size(); i++) {
                if(!answers.count(ogtarget)) {
                    answers[ogtarget]={{}};
                }
                for (int j = 0; j < answers[target][i].size(); j++) {
                    answers[ogtarget].back().push_back(answers[target][i][j]);
                }
                for (int j = 0; j < cursum.size(); j++) {
                    answers[ogtarget].back().push_back(cursum[j]);
                }

            }
        } else {
            if (target == 0) {
                curanswers.push_back({});
                for(int i=0; i< cursum.size(); i++) {
                    curanswers.back().push_back(cursum[i]);
                }
                cursum.clear();
                return;
            } else {
                for (int i = 0; i < candidates.size(); i++) {
                    if(target<candidates[i]) {
                        continue;
                    }
                    cursum.push_back(candidates[i]);
                    getAns(answers, curanswers, cursum, candidates, target-candidates[i], target);
                }
                answers.insert({target, curanswers});
                curanswers.clear();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        unordered_map<int, vector<vector<int>>> answers;
        vector<vector<int>> curanswers;
        vector<int> cursum;
        getAns(answers, curanswers, cursum, candidates, target, target);
        return answers[target];
    }
};

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    Solution soln;
    vector<vector<int>> ans = soln.combinationSum(candidates, target);
    for(auto &x: ans) {
        cout<<"[";
        for(auto &y: x) {
            cout<<y<<",";
        }
        cout<<"],";
    } 
}