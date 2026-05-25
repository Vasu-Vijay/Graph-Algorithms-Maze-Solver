class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left=0, right=0, sum=0, maxm=nums[0]; 
        for(; right<nums.size(); right++) {
            if(sum<0) {
                left=right;
                sum=0;
            }
            sum+=nums[right];
            maxm=max(sum, maxm);
        }
        return maxm;
    }
};