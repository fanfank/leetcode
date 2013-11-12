class Solution {//this code is a reference of http://blog.csdn.net/sunjilong/article/details/8668316
public:
    int minCut(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int sz = s.size();
        vector<int> dp(sz+1);//dp[i] means minCut of substr s[i, sz-1];
        vector<vector<int> > ispal(sz, vector<int>(sz, 0));
        for(int i = 0; i <= sz; ++i) {
            dp[i] = sz - i - 1;
        }
        for(int i = sz - 1; i >= 0; --i) {
            for(int j = i; j < sz; ++j) {
                if(s[i] == s[j] && (j - i < 2 || ispal[i+1][j-1])) {
                    ispal[i][j] = 1;
                    dp[i] = min(dp[i], 1+dp[j+1]);
                }
            }
        }
        return dp[0]>=0?dp[0]:0;
    }
};