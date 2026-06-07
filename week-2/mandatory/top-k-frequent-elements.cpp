class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> freqs;
        for(int i=0; i<n; i++) {
            freqs[nums[i]]++;
        }
        vector<pair<int,int>> map;
        for(auto it=freqs.begin(); it!=freqs.end(); it++) {
            map.push_back({it->second, it->first});
        }
        sort(map.begin(), map.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });
        vector<int> ans(k);
        for(int i=0; i<k; i++) {
            ans[i]=map[i].second;
        }
        return ans;
    }
};