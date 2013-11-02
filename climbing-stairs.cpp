class Solution {
public:
    int climbStairs(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n == 1) {
            return 1;
        } else if(n == 2) {
            return 2;
        }
        int num[2] = {1, 2};
        int index = 0;
        for(int i = n - 2; i > 0; --i) {
            num[index] = num[0] + num[1];
            index ^= 1;
        }
        return num[index^1];
    }
};