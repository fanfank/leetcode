/**********************************
 Solution 1 : logically complicate
 **********************************/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int sz = prices.size();
        int bpos = 0, spos = 0;
        int profit = 0;
        for(int i = 1; i < sz; ++i) {
            if(prices[i] > prices[spos]) {
                spos = i;
            } else if(prices[i] < prices[spos]) {
                profit += prices[spos] - prices[bpos];
                bpos = spos = i;
            }
        }
        if(bpos != spos)
            profit += prices[spos] - prices[bpos];
        return profit;
    }
};

/**********************************
 Solution 2 : logically simpler
 **********************************/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() == 0)
            return 0;
        int ans = 0;
        for (int i = 1; i < prices.size(); i++)
            if (prices[i] > prices[i - 1])
                ans += (prices[i] - prices[i - 1]);
        return ans;
    }
};