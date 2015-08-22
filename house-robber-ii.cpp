class Solution { 
public: 
    int rob(vector<int>& nums) { 
        size_t nums_size = nums.size();
        if (nums_size < 2) {
            return nums.empty() ? 0 : nums[0];
        }

        vector<vector<int> > dp_with0(nums_size, vector<int>(2, 0));
        vector<vector<int> > dp_without0(nums_size, vector<int>(2, 0));

        dp_with0[0][1] = nums[0];

        for (int32_t i = 1; i < nums_size; ++i) {
            dp_with0[i][0] = max(dp_with0[i-1][0], dp_with0[i-1][1]);
            dp_with0[i][1] = nums[i]
                    + max(dp_with0[i-1][0],
                        i - 2 >= 0 ? 
                            max(dp_with0[i-2][0], dp_with0[i-2][1]) : 0);

            dp_without0[i][0] = max(dp_without0[i-1][0], dp_without0[i-1][1]);
            dp_without0[i][1] = nums[i]
                    + max(dp_without0[i-1][0],
                        i - 2 >= 0 ? 
                            max(dp_without0[i-2][0], dp_without0[i-2][1]) : 0);
        }
        
        int res = max(
                max(dp_with0[nums_size-2][0], dp_with0[nums_size-2][1]),
                max(dp_without0[nums_size-1][0], 
                    dp_without0[nums_size-1][1]));

        return res;
    } 
};
