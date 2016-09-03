class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) {
            return vector<int>();
        }

        int sz = nums.size();
        vector<int> ans(sz);
        ans[sz-1] = nums[sz-1];
        for (int i = sz - 2; i >= 0; --i) {
            ans[i] = ans[i+1] * nums[i];
        }

        int lp = 1;
        for (int i = 0; i < sz; ++i) {
            if (i == sz - 1) {
                ans[i] = lp * 1;
            } else {
                ans[i] = lp * ans[i+1];
            }
            lp *= nums[i];
        }

        return ans;
    }
};
