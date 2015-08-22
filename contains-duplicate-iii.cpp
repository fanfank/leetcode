class Solution { 
public: 
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) { 
        if (k <= 0) {
            return false;
        }

        //we need a data structure that inserts/deletes easily
        //and can locate a specific element easily
        //a balanced binary tree will be appropriate
        multiset<int64_t> bbt;
        int64_t i64t = t;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (bbt.size() > k) {
                bbt.erase(bbt.find(nums[i-k-1]));
            }

            auto iter = bbt.lower_bound(nums[i]);
            auto before = iter;
            if (before != bbt.begin() && !bbt.empty()) {
                --before;
            }

            if (iter != bbt.end() && abs(nums[i] - *iter) <= i64t) {
                return true;
            } else if (before != bbt.end() && abs(nums[i] - *before) <= i64t) {
                return true;
            } else {
                bbt.insert(nums[i]);
            }
        }

        return false;
    } 
};
