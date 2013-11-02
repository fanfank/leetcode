class Solution {
public:
    int res, rwsz, clsz, *dp;
    int minPathSum(vector<vector<int> > &grid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        rwsz = grid.size(), clsz = grid[0].size();
        dp = new int[clsz];
        
        dp[0] = grid[0][0];
        for(int i = 1; i < clsz; ++i)
            dp[i] = grid[0][i] + dp[i-1];
        for(int i = 1; i < rwsz; ++i)
            for(int j = 0; j < clsz; ++j)
                if(j == 0) {
                    dp[j] += grid[i][j];
                } else {
                    dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
                }
        
        res = dp[clsz - 1];
        delete []dp;
        return res;
    }
};
