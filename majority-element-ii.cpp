class Solution { 
public: 
    int majority[2], count[2];
    vector<int> majorityElement(vector<int>& nums) { 
        majority[0] = 1; majority[1] = 2;
        count[0]    = 0; count[1]    = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == majority[0]) {
                ++count[0];
            } else if (nums[i] == majority[1]) {
                ++count[1];
            } else if (count[0] == 0) {
                majority[0] = nums[i];
                count[0] = 1;
            } else if (count[1] == 0) {
                majority[1] = nums[i];
                count[1] = 1;
            } else {
                --count[0];
                --count[1];
            }
        }

        count[0] = count[1] = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            count[0] += (nums[i] == majority[0] ? 1 : 0);
            count[1] += (nums[i] == majority[1] ? 1 : 0);
        }

        vector<int> res;
        if (count[0] > nums.size() / 3) {
            res.push_back(majority[0]);
        }
        if (count[1] > nums.size() / 3) {
            res.push_back(majority[1]);
        }

        return res;
    } 
};
