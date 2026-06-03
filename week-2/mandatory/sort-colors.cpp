class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(), n0=0, n1=0, n2=0;
        for(auto v: nums) {
            if(v==0) n0++;
            else if(v==1) n1++;
            else if(v==2) n2++;
        }
        n1+=n0;
        n2+=n1;
        for(int i=0; i<n; i++) {
            if(i<n0) {
                nums[i]=0;
            } else if(i<n1) {
                nums[i]=1;
            } else {
                nums[i]=2;
            }
        }
    }
};