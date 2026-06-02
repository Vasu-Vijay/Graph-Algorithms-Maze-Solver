class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int n = piles.size(), sum=0;
        auto max_it = max_element(piles.begin(), piles.end());
        if(h==n) {
            return *max_it;
        }
        for(auto v: piles) {
            sum+=v;
        }
        int min_k = max(sum / h, 1LL), max_k = *max_it;
        int l=min_k, r=max_k, mid; 
        while(r>l) {
            sum=0;
            mid = (l+r)/2;
            for(auto v: piles) {
                sum+= ceil((v*1.0)/mid);
            }
            if(sum<=h) {
                r=mid;
            } else {
                l=mid+1;
            }
        }
        return l;
    }
};