class Solution {
public:
    int jump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n <= 1)
            return 0;
        int last = 0;
        vector<int> v(n);
        v[0] = 0;
        for(int i = 0; last < (n - 1) && i < n; ++i) {
            for(int j = last + 1; j < n && j <= i + A[i]; ++j)
                v[j] = v[i] + 1;
            last = max(last, i + A[i]);
        }
        return v[n-1];
    }
};