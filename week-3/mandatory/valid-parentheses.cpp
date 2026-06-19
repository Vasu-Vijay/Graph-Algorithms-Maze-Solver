class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        for(int i=0; i<s.size(); i++) {
            if((s[i]==')' && (stck.empty() || stck.top() != '(')) || (s[i]=='}' && (stck.empty() || stck.top()!='{')) || (s[i]==']' && (stck.empty() || stck.top()!='['))) {
                return false;
            }
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
                stck.push(s[i]);
            } else {
                stck.pop();
            }
        }
        return stck.empty();
    }
};