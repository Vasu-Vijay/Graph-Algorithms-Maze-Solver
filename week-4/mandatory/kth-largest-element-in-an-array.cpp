class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }

    void siftDown(vector<int>& nums, int i, int n) {
        int left, right;
        left = 2*i+1; 
        right = 2*i+2;
        while(right<n) {
            if(nums[i]>=nums[left] && nums[i]>=nums[right]) {
                break;
            }
            swap(nums, i, left>right?left:right);
            left = 2*i+1; 
            right = 2*i+2;
        }
        if(left<n && nums[left]>nums[i]) {
            swap(nums, i, left);
        }
    }

    void heapify(vector<int>& nums) {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            siftDown(nums, i, n);
        }
    }

    int extractMax(vector<int>& heap) {
        int last = heap.back();
        int front = heap[0];
        heap.pop_back();
        siftDown(heap, 0, heap.size());
        return front;
    }

    int findKthLargest(vector<int>& nums, int k) {
        heapify(nums); 
        int ans;
        for(int i=0; i<k; i++) {
            ans = extractMax(nums);
        }
        return ans;
    }
};