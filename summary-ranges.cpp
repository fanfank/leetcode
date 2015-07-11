class Solution { 
public: 
    vector<string> summaryRanges(vector<int>& nums) { 
        vector<string> range_vector;
        size_t nums_size = nums.size();
        if (nums_size == 0) {
            return range_vector;
        }

        int last_num = nums[0];
        for (size_t i = 1; i < nums_size; ++i) {
            if (nums[i] != nums[i-1] + 1) {
                addRange(range_vector, last_num, nums[i-1]);
                last_num = nums[i];
            }
        }
        addRange(range_vector, last_num, nums.back());
        return range_vector;
    } 

    void addRange(vector<string>& range_vector, int left, int right) {
        char range[32];
        if (left == right) {
            snprintf(range, sizeof(range), "%d", left);
        } else {
            snprintf(range, sizeof(range), "%d->%d", left, right);
        }
        range_vector.push_back(range);
    }
};
