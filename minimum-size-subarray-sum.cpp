//Solution 1: O(n) space, O(n^2) time
class Solution { 
private:
    vector<int> dp;
public: 
    int minSubArrayLen(int s, vector<int>& nums) { 
        size_t nums_size = nums.size();
        dp.assign(nums_size, 0);
        for (int i = 0; i < nums_size; ++i) {
            for (int j = 0; i + j < nums_size; ++j) {
                dp[j] += nums[i+j];
                if (dp[j] >= s) {
                    return i + 1;
                }
            }
        }
        return 0;
    } 
};

//Solution 2: O(1) space, O(n) time
class Solution { 
public: 
    int minSubArrayLen(int s, vector<int>& nums) { 
        size_t nums_size = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int res = 0x7fffffff;
        for (size_t i = 0; i < nums_size; ++i) {
            right = i;
            sum += nums[right];
            while (sum >= s && left <= right) {
                res = min(res, right - left + 1);
                sum -= nums[left++];
            }
        }
        return res == 0x7fffffff ? 0 : res;
    } 
};
