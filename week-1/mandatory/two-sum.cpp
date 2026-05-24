class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> ognums = nums;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int req = target - nums[i];
            int left = 0, right = nums.size() - 1, mid;
            while (right - left > 0) {
                mid = (left + right) / 2;
                if (req > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            mid = left;
            if (mid == i) {
                if (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                    mid = i + 1;
                } else {
                    continue;
                }
            }
            if (nums[mid] == req) {
                int ogi = -1, ogmid = -1;
                for (int j = 0; j < ognums.size(); j++) {
                    if (ogi == -1 && ognums[j] == nums[i]) {
                        ogi = j;
                        continue;
                    }
                    if (ogmid == -1 && ognums[j] == nums[mid]) {
                        ogmid = j;
                    }
                }
                vector<int> ans = {ogi, ogmid};
                return ans;
            }
        }
        vector<int> ans = {0, 1};
        return ans;
    }
};