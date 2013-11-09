class Solution {
public:
    int maxSubArray(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int res = 0x80000000, sum = 0;
        for(int i = 0; i < n; ++i) {
            if(sum < 0) {
                sum = A[i];
            } else {
                sum += A[i];
            }
            res = max(res, sum);
        }
        return res;
    }
};