class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxm = 0;
        stack<int> stL, stR;
        vector<int> left(n, -1), right(n, n);
        for (int i = 0; i < n; i++) {
            while (!stR.empty() && heights[stR.top()] > heights[i]) {
                right[stR.top()] = i;
                stR.pop();
            }
            stR.push(i);
        }

        for(int i=n-1; i>=0; i--) {
            while (!stL.empty() && heights[stL.top()] > heights[i]) {
                left[stL.top()] = i;
                stL.pop();
            }
            stL.push(i);
        }
        
        for(int i=0; i<n; i++) {
            maxm = max(maxm, (right[i] - left[i] - 1) * heights[i]);
        }

        return maxm;
    }
};