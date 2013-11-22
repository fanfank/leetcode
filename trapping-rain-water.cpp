class Solution {
public:
    int trap(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n < 3)
            return 0;
        int res = 0;
        vector<int> lmax(n), rmax(n);
        lmax[0] = A[0];
        rmax[n-1] = A[n-1];
        for(int i = 1; i < n; ++i) {
            lmax[i] = max(lmax[i-1], A[i]);
            rmax[n-1-i] = max(rmax[n-i], A[n-1-i]);
        }
        for(int i = 0; i < n; ++i) {
            int height = min(lmax[i], rmax[i]);
            if(height > A[i]) {
                res += height - A[i];
            }
        }
        return res;
    }
};