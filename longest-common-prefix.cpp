class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {//Trie
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        string res = "";
        if(strs.empty())
            return res;
        for(int i = 0; i < strs[0].size(); ++i) {
            for(int j = 1; j < strs.size(); ++j) {
                if(i >= strs[j].size() || strs[0][i] != strs[j][i])
                    return res;
            }
            res.append(1, strs[0][i]);
        }
        return res;
    }
};