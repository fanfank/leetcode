class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int pa = m - 1, pb = n - 1, pr = m + n - 1;
        while(pa >= 0 && pb >= 0) {
            if(A[pa] > B[pb])
                A[pr--] = A[pa--];
            else
                A[pr--] = B[pb--];
        }
        while(pb >= 0)
            A[pr--] = B[pb--];
    }
};