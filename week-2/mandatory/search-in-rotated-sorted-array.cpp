class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1) { return nums[0]==target?0:-1; }
        int l=0, r=n-2, mid;
        while(r>l) {
            mid = (l+r)/2;
            if(nums[mid]<nums[n-1]) {
                r=mid;
            } else {
                l=mid+1;
            }
        }

        // l;
        int k = l;
        if(nums[l]>nums[n-1]) {
            k=n-1;
        }
        l=0; r=n-1;
        cout<<l<<"l "<<r<<"r "<<k<<"k \n";
        while(r>l) {
            mid = (l+r) /2;
            if(nums[(mid+k)%n]>=target) {
                r=mid;
            }  else {
                l=mid+1;
            }
        }
        return nums[(l+k)%n] == target ? (l+k)%n: -1;
    }
};