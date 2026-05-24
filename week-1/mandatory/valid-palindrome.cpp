class Solution {
public:
    bool isPalindrome(string s) {
        string low_s=s;
        int temp, temp2;
        //make lower
        for(int i=0; i<low_s.length(); i++) {
            temp = low_s[i]-'A';
            if(temp>=0 && temp<=26) {
                low_s[i] = char(char(temp)+'a');
            }
        }
        //check palin
        int left=0, right=low_s.length()-1;
        for(; left<low_s.length() && right>=0;) {
            temp = low_s[left]-'a';
            temp2=low_s[left]-'0';
            if((temp<0 || temp>25) && (temp2<0 || temp2>9)) {
                left++;
                continue;
            } 
            temp = low_s[right]-'a';
            temp2=low_s[right]-'0';
            if((temp<0 || temp>25) && (temp2<0 || temp2>9)) {
                right--;
                continue;
            }
            if(right<=left) {break;}
            if(low_s[left]!=low_s[right]) {
                break;
            }
            left++; right--;
        }
        return (right<=left);
    }
};