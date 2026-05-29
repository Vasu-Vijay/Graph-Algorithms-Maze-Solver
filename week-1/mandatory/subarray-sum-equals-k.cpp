class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), reqnum, ans=0;
        vector<int> cumsum(n, 0); 
        unordered_multimap<int, int> map;
        cumsum[0]=nums[0];
        if(cumsum[0]==k) { ans++; }
        map.insert({cumsum[0], 0});
        for(int i=1; i<n; i++) {
            cumsum[i]=cumsum[i-1]+nums[i];
            if(cumsum[i]==k) ans++;
            map.insert({cumsum[i], i});
            reqnum=cumsum[i]-k;
            auto p=map.equal_range(reqnum);
            for(auto reqi=p.first; reqi!=p.second; reqi++) {
                if(reqi!=map.end() && reqi->second != i) {
                    ans++;
                }
            }
            
        }
        return ans;
    }
};