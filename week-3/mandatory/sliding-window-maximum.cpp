class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;

        //handle first window
        for(int i=0; i<k; i++) {
            while(!dq.empty() && dq.back() < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        ans.push_back(dq[0]);

        //handle later windows
        int l=0, r = k-1;
        while(r+1<n) {
            if(dq[0] == nums[l]) {
                dq.pop_front();
            }

            while(!dq.empty() && dq.back() < nums[r+1]) {
                dq.pop_back();
            }
            dq.push_back(nums[r+1]);
            l++; r++;
            ans.push_back(dq[0]);
        }
        return ans;
    }
};