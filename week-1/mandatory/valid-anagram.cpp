class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0);
        int slen = s.length(), tlen=t.length();
        if(slen!=tlen) { return false; }
        for(int i=0; i<slen; i++) {
            freq[s[i]-'a']++;
        }
        for(int i=0; i<tlen; i++) {
            if(freq[t[i]-'a']<=0) { return false; }
            freq[t[i]-'a']--;
        }
        return true;
    }
};