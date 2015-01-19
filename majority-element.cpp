class Solution {
public:
    int majorityElement(vector<int> &num) {
        int current_majority = num[0];
        int majority_count   = 1;
        for (int i = 1; i < num.size(); ++i) {
            if (majority_count > 0) {
                majority_count += (num[i] == current_majority ? 1 : -1);
            } else {
                current_majority = num[i];
                majority_count   = 1;
            }
        }
        return current_majority;
    }
};
