class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 1;
        int len = s.length();
        if(len==0) { return 0; }
        int done[200] = {0};
        for(int r=0, l=0; r<len; r++) {
            if(done[int(s[r])]) {
                while(s[l]!=s[r]) {
                    done[int(s[l])]=0;
                    l++;
                }
                l++;
            } else {
                ans=max(ans, r-l+1);
                done[int(s[r])]=1;
            }
        }
        return ans;
    }
};