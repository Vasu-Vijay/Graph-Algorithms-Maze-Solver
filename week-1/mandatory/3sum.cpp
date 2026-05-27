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
            reqsum = -nums[i];
            int left=i+1, right=nums.size()-1;
            while(right-left>=1) {
                if(nums[left]+nums[right]>reqsum) {
                    right--;
                    continue;
                }
                if(nums[left]+nums[right]<reqsum) {
                    left++;
                    continue;
                }
                ans.push_back({nums[i], nums[left], nums[right]});
                left++; right--;
                while(left<nums.size() && nums[left-1]==nums[left]) left++;
                while(right>=0 && nums[right+1]==nums[right]) right--;
            }
        }
        return ans;
    }
};