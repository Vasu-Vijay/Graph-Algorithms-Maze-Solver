class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), vol=0;
        vector<int> premax(n,0), postmax(n,0);
        for(int i=1, j=n-2; i<n; i++, j--) {
            premax[i] = max(height[i-1], premax[i-1]);
            postmax[j] = max(height[j+1], postmax[j+1]);
        }
        for(int i=1; i<n-1; i++) {
            vol+= max(0, min(premax[i], postmax[i]) - height[i]);
        }
        return vol;
    }
};    