class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> done;
        int n = nums.size();
        int ans=0;
        for(int i=0; i<n; i++) {
            if(done.count(nums[i])) {
                ans-=nums[i];
            } else {
                ans+=nums[i];
                done.insert(nums[i]);
            }
        }
        return ans;
    }    
};