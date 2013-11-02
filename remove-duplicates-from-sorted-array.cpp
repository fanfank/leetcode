class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n <= 0)
            return n;
        int pos = 0, last = A[0] + 1;
        for(int i = 0; i < n; ++i) {
            if(last == A[i]) {
                continue;
            } else {
                last = A[i];
                A[pos++] = A[i];
            }
        }
        return pos;
    }
};