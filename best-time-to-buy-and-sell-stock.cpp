class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(prices.empty())
            return 0;
        stack<int> sta;
        int num = prices.back();
        sta.push(num);
        for(int i = prices.size() - 2; i >= 0; sta.push(num), --i)
            if(prices[i] > num) {
                num = prices[i];
            }
        num = 0;
        for(int i = 0; i < prices.size(); ++i, sta.pop())
            num = max(num, sta.top() - prices[i]);
        return num;
    }
};