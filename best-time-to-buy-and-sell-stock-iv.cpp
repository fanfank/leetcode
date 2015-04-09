//Solution 1: 非主流的dp解法，使用了交易是否完成作为下标之一
//            An obscure dp solution
//            time: O(nk) for normal cases, O(n) for corner cases
//            space: O(n), actually O(2*(k+1)), but in the following 2*k >= n
//            20ms
class Solution {
public:
    const int64_t NEGAINFI = 0x80000000ffffffff;
    int maxProfit(int k, vector<int> &prices) {
        //dp[i][j][0] => max profit in the ith day and finished j
        //               transactions with and no transactions running
        //dp[i][j][1] => max profit in the ith day and finished j
        //               transactions with one transaction running
        //dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1] + prices[i-1])
        //dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0]   - prices[i-1])
        //i in [1, n], j in [1, k];
        //where n = prices.size()
        //Observe that we can compress the space of dp since dp[i][j][0]
        //and dp[i][j][1] don't need to know the values of dp[0,i-2][0,j][...]
        //thus we use dp[j][0] and dp[j][1]
        if (k < 1 || prices.size() < 2) {
            return 0;
        }

        if (k * 2 >= prices.size()) {
            return directCompute(prices);
        }
            
        vector<vector<int64_t> > dp(k+1, vector<int64_t>(2, NEGAINFI));
        dp[0][0] = 0;
        dp[0][1] = 0 - prices[0];

        for (int i = 2; i <= prices.size(); ++i) {   //day
            for (int j = min(k, i-1); j >= 1; --j) { //transaction
                dp[j][1] = max(dp[j][1], dp[j][0] - prices[i-1]);
                dp[j][0] = max(dp[j][0], dp[j-1][1] + prices[i-1]);
            }   
            dp[0][1] = max(dp[0][1], (int64_t)0 - prices[i-1]);
        }

        int64_t res = NEGAINFI;
        for (int i = 0; i <= k; ++i) {
            res = max(res, dp[i][0]);
        }   

        return res > 0 ? (int)res : 0;
    }   

    int directCompute(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1]) {
                res += prices[i] - prices[i-1];
            }
        }
        return res;
    }
};

//Solution 2: 较常规的dp解法，但是感觉压缩之后理解更难
//            A normal dp solution, yet with compression of dp this is
//              somehow much difficult to understand
//            time: same as Solution 1
//            space: O(2*n)
//            15ms
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        //dp[i][j] => max profit after ith transaction before the jth day
        //dp[i][j] = 
        //      max(dp[i][j-1], max(dp[i-1][h] - prices[h-1] + prices[j-1])))
        //         = 
        //      max(dp[i][j-1], max(dp[i-1][h] - prices[h-1]) + prices[j-1])
        //
        //Where i in [1, k], j in [1, n], h in [1, j-1]
        //  n <= prices.size()
        //
        //Observe that dp[i][j] relevant only to dp[i-1][...], thus space of
        //  dp can be compressed, use dp[j] instead
        //And find a way to preserve max(dp[i-1][h] - prices[h-1]) to avoid
        //  extra time consumption

        if (k < 1 || prices.size() < 2) {
            return 0;
        }
        
        if (k * 2 >= prices.size()) {
            return directCompute(prices);
        }

        vector<int> dp(prices.size() + 1, 0);
        vector<int> last_day_max(prices.size() + 1, 0x80000000);

        for (int i = 1; i <= prices.size(); ++i) {
            last_day_max[i] = max(last_day_max[i-1], 0 - prices[i-1]);
        }

        for (int i = 1; i <= k; ++i) { 
            int preserve_day_max = last_day_max[1];
            for (int j = 1; j <= prices.size(); ++j) {
                dp[j] = max(dp[j-1], preserve_day_max + prices[j-1]);
                preserve_day_max = last_day_max[j];
                last_day_max[j] = max(last_day_max[j-1], dp[j] - prices[j-1]);
            }
        }

        int res = 0x80000000;
        for (int i = 1; i <= prices.size(); ++i) {
            res = max(res, dp[i]);
        }

        return res;
    }

    int directCompute(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1]) {
                res += prices[i] - prices[i-1];
            }
        }
        return res;
    }
};

