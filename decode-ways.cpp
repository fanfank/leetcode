/************************************
 Solution 1: a bad solution, written in 2013
 ************************************/
class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const int sz = s.size();
        if(sz == 0)
            return 0;
            
        int *ans = new int[sz];
        if(s[0] == '0')
        {
            delete []ans;
            return 0;
        }
        else
            ans[0] = 1;
            
        int zeros = (s[0]>'2'?1:0);
        for(int i = 1; i < sz; ++i)
        {
            if(s[i] == '0')
            {
                if(zeros == 1)
                {
                    delete []ans;
                    return 0;
                }
                zeros = 1;
                if((i-2) >= 0)
                    ans[i] = ans[i-2];
                else
                    ans[i] = ans[i-1];
                continue;
            }
            zeros = 0;
            
            if(s[i-1] == '0' || s[i-1] > '2')
                ans[i] = ans[i-1];
            else if(s[i-1] == '1')
                ans[i] = ans[i-1] + (i-2>=0?ans[i-2]:1);
            else if(s[i-1] == '2')
                if(s[i] < '7')
                    ans[i] = ans[i-1] + (i-2>=0?ans[i-2]:1);
                else
                    ans[i] = ans[i-1];
            
            if(s[i] > '2')
                zeros = 1;
        }
        int tmp = ans[sz-1];
        delete []ans;
        return tmp;
    }
};

/************************************
 Solution 1: a better solution, written in 2014
 ************************************/
class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0')
        return 0;
        vector<int> dp(s.size(), 0);
        dp[0] = 1;
        for(int i = 1; i < s.size(); ++i) {
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7')) {
                if(s[i] != '0') {
                    dp[i] = dp[i-1] + (i-2>=0?dp[i-2]:1);
                } else {
                    dp[i] = (i-2>=0?dp[i-2]:1);
                }
            } else if(s[i] == '0') {
                return 0;
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp.back();
    }
};
