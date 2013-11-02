class Solution {
public:
    bool match(char c1, char c2) {
        return ((c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}') || (c1 == '(' && c2 == ')'));
    }
    bool isValid(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        stack<char> sta;
        int sz = s.size();
        for(int i = 0; i < sz; ++i) {
            if(s[i] == '[' || s[i] == '{' || s[i] == '(')
                sta.push(s[i]);
            else if(s[i] == ']' || s[i] == '}' || s[i] == ')') {
                if((!sta.empty()) && match(sta.top(), s[i]))
                    sta.pop();
                else
                    return false;
            }
            else
                return false;
        }
        if(sta.empty())
            return true;
        return false;
    }
};