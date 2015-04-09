//Solution 1: dp solution
//            time: O(n)
//            space: O(1)
//            3ms
class Solution {
public:
    int rob(vector<int> &num) {
        //dp[i][0] => max money from 0~i house with the ith house not robbed
        //dp[i][1] => max money from 0~i house with the ith house robbed
        //dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        //dp[i][1] = dp[i-1][0] + num[i];
        //dp space can be compressed
        if (num.empty()) {
            return 0;
        }

        int dp[2] = {0, num[0]};
        int tmp = 0;
        for (int i = 1; i < num.size(); ++i) {
            tmp = dp[0];
            dp[0] = max(dp[0], dp[1]);
            dp[1] = tmp + num[i];
        }
        
        return max(dp[0], dp[1]);
    }
};
