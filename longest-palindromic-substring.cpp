class Solution {//manacher
public:
    string longestPalindrome(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int sz = s.size() * 2 + 1;
        vector<char> es(sz, '#');
        vector<int> v(sz, 0);
        for(int i = 0; i < s.size(); ++i)
            es[2*i+1] = s[i];
        int right = 0, center = 0, max_gap = 0, res_index = 0;
        for(int i = 1; i < sz; ++i) {
            if(right > i) {
                v[i] = min(v[center*2-i], right - i);
            }
            while((i-v[i] >= 0) && (i+v[i] < sz) && (es[i-v[i]] == es[i+v[i]]))
                ++v[i];
            --v[i];
            if(i + v[i] > right) {
                center = i;
                right = i + v[i];
            }
            if(v[i] > max_gap) {
                max_gap = v[i];
                res_index = i;
            }
        }
        string ans = "";
        for(int i = res_index - v[res_index]; i <= res_index + v[res_index]; ++i)
            if(es[i] != '#')
                ans.append(1, es[i]);
        return ans;
    }
};