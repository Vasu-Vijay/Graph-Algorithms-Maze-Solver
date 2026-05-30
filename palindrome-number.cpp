class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) {return false;}
        long long int last, rev=0, ogx=x;
        while(x>0) {
            last = x%10;
            rev*=10;
            rev+=last;
            x=x/10;
        }
        return ogx==rev;
    }
};