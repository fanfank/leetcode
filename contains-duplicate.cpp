class Solution { 
public: 
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 0) {
            return false;
        }

        srand(time(NULL));
        size_t nums_size = nums.size();
        size_t start_index = rand() % nums_size; //avoid worst case
        std::set<int> nums_set;
        for (size_t i = 0; i < nums_size; ++i) {
            int index = (i + start_index) % nums_size;
            if (nums_set.find(nums[index]) != nums_set.end()) {
                return true;
            }
            nums_set.insert(nums[index]);
        }
        return false;
    }
};
