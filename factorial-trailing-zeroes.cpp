class Solution {
public:
    int trailingZeroes(int n) {
        if (n == 0) {
            return 0;
        }
        int max_num_of_5 = n / 5;
        return max_num_of_5 + trailingZeroes(max_num_of_5);
    }
};
