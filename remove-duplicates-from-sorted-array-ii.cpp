class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n <= 0)
            return n;
        bool dup = false;
        int last = A[0] + 1, pos = 0;
        for(int i = 0; i < n; ++i) {
            if(last == A[i]) {
                if(dup)
                    continue;
                dup = true;
                A[pos++] = last;
            } else {
                dup = false;
                last = A[i];
                A[pos++] = A[i];
            }
        }
        return pos;
    }
};