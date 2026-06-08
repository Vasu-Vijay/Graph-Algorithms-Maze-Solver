class Solution {
  public:
    vector<vector<int>> permute(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) {
            return {{nums[0]}};
        }
        vector<vector<int>> ans;

        // form nums-1
        vector<int> nums1;
        //skip first
        for (int j = 1; j < n; j++) {
            nums1.push_back(nums[j]);
        }
        auto small = permute(nums1);

        for (int i = 0; i < small.size(); i++) {
            // each permuation, n places
            int adjust = 0;
            vector<int> oneperm;
            for (int j = 0; j < n; j++) {
                adjust = 0;
                for (int k = 0; k < n; k++) {
                    if (k == j) {
                        oneperm.push_back(nums[0]);
                        adjust = -1;
                    } else {
                        oneperm.push_back(small[i][k + adjust]);
                    }
                }
                ans.push_back(oneperm);
                oneperm.clear();
            }
            // //for j=n-1
            // oneperm = small[l];
            // oneperm.push_back(nums[i]);
            // ans.push_back(oneperm);
        }
        return ans;
    }
};