class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), reqnum, ans=0, cumsum=0;
        unordered_map<int, int> map;
        for(int i=0; i<n; i++) {
            cumsum+=nums[i];
            if(cumsum==k) ans++;

            reqnum=cumsum-k;
            ans+=map[reqnum];
            map[cumsum]+=1;
        }
        return ans;
    }
};