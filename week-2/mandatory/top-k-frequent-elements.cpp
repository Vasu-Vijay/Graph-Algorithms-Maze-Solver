class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int prev = nums[0], n = nums.size(), count = 1, maxcount = 1;
        if (n == 1) {
            return {nums[0]};
        }
        queue<int> q;
        bool qmade = false;
        vector<pair<int, int>> tempq;
        for (int i = 1; i < n; i++) {
            if (nums[i] == prev) {
                count++;
            } else {
                if (qmade) {
                    if (count >= maxcount) {
                        maxcount = count;
                        q.push(prev);
                        if (q.size() > k) {
                            q.pop();
                        }
                    }
                } else {
                    tempq.push_back({prev, count});
                    if (tempq.size() == k) {
                        qmade = true;
                        sort(tempq.begin(), tempq.end(),
                             [](const auto& a, const auto& b) {
                                 return a.second < b.second;
                             });
                        maxcount = tempq[k-1].second;
                        for (int j = 0; j < k; j++) {
                            q.push(tempq[j].first);
                        }
                    }
                }
                prev = nums[i];
                count = 1;
            }
        }
        if (qmade) {
            if (count >= maxcount) {
                maxcount = count;
                q.push(prev);
                if (q.size() > k) {
                    q.pop();
                }
            }
        } else {
            tempq.push_back({prev, count});
            if (tempq.size() == k) {
                qmade = true;
                sort(tempq.begin(), tempq.end(),
                     [](const auto& a, const auto& b) {
                         return a.second < b.second;
                     });
                for (int j = 0; j < k; j++) {
                    q.push(tempq[j].first);
                }
            }
        }
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = q.front();
            q.pop();
        }
        return ans;
    }
};

// -2, -1, -1, 0, 1, 2, 3, 4, 4, 4

// -9, -3, -1, -1, 1, 2, 2, 3, 3, 3, 3, 5, 7, 7, 7, 9, 9, 10, 10, 10

//-9 -3 -1 2 3