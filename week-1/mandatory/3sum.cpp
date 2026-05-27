class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int reqsum=0, req;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            if(i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            set <int> covered;
            set <int> done;
            reqsum=-nums[i];
            for(int j=i+1; j<nums.size(); j++) {
                req=reqsum - nums[j];
                if(covered.count(req) && !done.count(nums[j])) {
                    ans.push_back({nums[i], nums[j], req});
                    done.insert(nums[j]);
                    done.insert(req);
                }
                covered.insert(nums[j]);
            }
        }
        return ans;
    }
};