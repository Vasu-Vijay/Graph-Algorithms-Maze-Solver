class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        if(n==0) { return {{}}; }
        int last = nums[n-1];
        nums.pop_back();
        auto smaller = subsets(nums);
        int s=smaller.size();
        for(int i=0; i<s; i++) {
            smaller.push_back(smaller[i]);
            smaller.back().push_back(last);
        }
        nums.push_back(last);
        return smaller;
    }
};