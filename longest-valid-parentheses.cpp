class Solution {
public:
    int longestValidParentheses(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int sz = s.size(), cnt = 0, res = 0;
        vector<bool> valid(sz, false);
        stack<int> sta;
        for(int i = 0; i < sz; ++i) {
            if(s[i] == '(') {
                sta.push(i);
            } else {
                if(!sta.empty()) {
                    valid[sta.top()] = valid[i] = true;
                    sta.pop();
                } else {
                    while(!sta.empty())
                        sta.pop();
                }
            }
        }
        for(int i = 0; i < sz; ++i) {
            if(valid[i]) {
                ++cnt;
                res = max(res, cnt);
            } else {
                cnt = 0;
            }
        }
        return res;
    }
};