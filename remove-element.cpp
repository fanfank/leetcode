class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(elem == A[i]) {
                ++cnt;
            } else {
                A[i-cnt] = A[i];
            }
        }
        return n - cnt;
    }
};