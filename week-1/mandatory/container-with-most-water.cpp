class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left=0, right=n-1, ans=0;
        while(right>left) {
            ans=max(ans, (right-left)*min(height[left], height[right]));
            if(height[left]<height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};