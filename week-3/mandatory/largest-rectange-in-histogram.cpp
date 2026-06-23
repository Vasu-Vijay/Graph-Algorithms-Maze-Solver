class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxm=0;
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()]>heights[i]) {
                maxm = max(maxm, (i - st.top()) * heights[st.top()]);
                st.pop();
            }
            st.push(i);
        }
        int first = n;
        while(!st.empty()) {
            first = st.top();
            st.pop();
        } 
        return max(maxm, (n-first) * heights[first]);
    }
};