class Solution {
public:
    char m[11][5] = {
        {0}, {0}, {3, 'a', 'b', 'c'}, {3, 'd', 'e', 'f'}, {3, 'g', 'h', 'i'},
        {3, 'j', 'k', 'l'}, {3, 'm', 'n', 'o'}, {4, 'p', 'q', 'r', 's'},
        {3, 't', 'u', 'v'}, {4, 'w', 'x', 'y', 'z'}, {0}
    } ;
    vector<string> letterCombinations(string digits) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int sz = digits.size();
        vector<string> ans({""});
        for(int i = 0; i < sz; ++i) {
            int ed = ans.size(), digit = digits[i] - '0';
            for(int j = 0; j < ed; ++j) {
                string stmp = ans[j];
                ans[j].append(1, m[digit][1]);
                for(int k = 2; k <= m[digit][0]; ++k)
                    ans.push_back(stmp + string(1, m[digit][k]));
            }
        }
        return ans;
    }
};