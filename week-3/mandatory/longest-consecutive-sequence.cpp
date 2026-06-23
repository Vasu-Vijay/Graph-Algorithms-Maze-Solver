class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=  nums.size();
        int ans=0, len=1;
        unordered_set<int> st;
        for(int i=0; i<n; i++) {
            st.insert(nums[i]);
        }
        for(auto it = st.begin(); it!=st.end(); it++) {
            //look for lessor
            int x = *it;
            while(st.count(--x)) {
                len++;
                st.erase(x);
            }
            //look for higher
            x = *it;
            while(st.count(++x)) {
                len++;
                st.erase(x);
            }
            ans = max(ans, len);
            len = 1;
        }
        return ans;
    }
};