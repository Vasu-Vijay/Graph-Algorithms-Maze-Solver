class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), reqnum, ans=0;
        vector<int> cumsum(n, 0); 
        unordered_map<int, int> map;
        cumsum[0]=nums[0];
        if(cumsum[0]==k) { ans++; }
        map.insert({cumsum[0], 1});
        for(int i=1; i<n; i++) {
            cumsum[i]=cumsum[i-1]+nums[i];
            if(cumsum[i]==k) ans++;
            
            reqnum=cumsum[i]-k;
            ans+=map[reqnum];
            map[cumsum[i]]+=1;
        }
        return ans;
    }
};