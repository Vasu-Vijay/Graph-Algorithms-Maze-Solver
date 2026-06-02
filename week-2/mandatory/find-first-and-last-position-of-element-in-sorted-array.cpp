class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) {return {-1, -1}; }
        int l=0, r=n-1, start=-1, end=-1, mid;
        while(r>l) {
            mid = (l+r)/2;
            if(nums[mid]>=target) {
                r=mid;
            } else {
                l=mid+1;
            }
        }
        if(nums[l]!=target) { return {-1, -1}; }
        start = l;
        l=0; r=n-1;
        while(r>l) {
            mid = (l+r) /2;
            if(nums[mid]>target) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        end = l-1;
        if(l==n-1 && nums[n-1] == target) {
            end++;
        }
        return {start, end};
    }
};