class Solution {
public:
    bool canJump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int cur = 0, last = 0;
        while(cur <= last && last < (n - 1)) {
            if(cur == last && A[cur] == 0)
                return false;
            last = max(last, cur + A[cur]);
            cur++;
        }
        return true;
    }
};