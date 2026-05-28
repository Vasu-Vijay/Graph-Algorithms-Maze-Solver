class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0) { return {0}; }
        vector<int> answer(n+1);
        int highest_power=1;
        answer[0] = 0; answer[1]=1;
        for(int i=2; i<n+1; i++) {
            if(i%highest_power==0) {
                highest_power*=2;
                answer[i]=1;
                continue;
            }
            answer[i] = answer[i-highest_power]+1;
        }
        return answer;
    }
};