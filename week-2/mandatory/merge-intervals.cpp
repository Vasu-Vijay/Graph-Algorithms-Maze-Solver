class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
            return a[0]<b[0];
        });
        int n = intervals.size();
        int cur_i=0;
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for(int i=1; i<n; i++) {
            if(intervals[i][0]<=merged[cur_i][1]) {
                merged[cur_i][1] = max(intervals[i][1], merged[cur_i][1]);
            } else {
                merged.push_back(intervals[i]);
                cur_i++;
            }
        }
        return merged;
    }
};