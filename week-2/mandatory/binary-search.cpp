class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(), l=0, r=n-1, mid;
        while(r>l) {
            mid = (l+r)/2;
            if(target > nums[mid]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return (nums[l]==target)?l:-1;

    }
};