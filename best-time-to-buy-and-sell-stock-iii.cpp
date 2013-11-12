class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int sz = prices.size();
        vector<int> profit1(sz);
        int maxprofit = 0, buyprice = 0x7fffffff, sellprice = 0x80000000, ans = 0;
        for(int i = 0; i < sz; ++i) {
            if(prices[i] < buyprice) {
                buyprice = prices[i];
            } else {
                maxprofit = max(maxprofit, prices[i] - buyprice);
            }
            profit1[i] = maxprofit;
        }
        maxprofit = 0;
        for(int i = sz - 1; i >= 0; --i) {
            if(prices[i] > sellprice) {
                sellprice = prices[i];
            } else {
                maxprofit = max(maxprofit, sellprice - prices[i]);
            }
            ans = max(ans, profit1[i] + maxprofit);
        }
        return ans;
    }
};