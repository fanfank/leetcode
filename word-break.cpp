class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<bool> dp(s.size(), false);
        for(int i = 0; i < s.size(); ++i) {
            for(int j = 0; j < i && !dp[i]; ++j) {
                if(!dp[j])
                    continue;
                dp[i] = (dict.find(s.substr(j+1, i-j))!=dict.end());
            }
            dp[i] = dp[i]?true:dict.find(s.substr(0, i+1))!=dict.end();
        }
        return dp[s.size()-1];
    }
};