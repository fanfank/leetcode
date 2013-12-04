class Solution {
public:
    int kthNum(int A[], int m, int B[], int n, int k) {
        if(m > n)
            return kthNum(B, n, A, m, k);
        if(m == 0)
            return B[k - 1];
        if(k == 1)
            return min(A[0], B[0]);
        int ia = min(m, k / 2), ib = k - ia;
        if(A[ia-1] < B[ib-1]) {
            return kthNum(A + ia, m - ia, B, n, k - ia);
        } else if(B[ib - 1] < A[ia - 1]) {
            return kthNum(A, m, B + ib, n - ib, k - ib);
        }
        return A[ia - 1];
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m+n)&1) {
            return kthNum(A, m, B, n, (m + n + 1) / 2);
        } else {
            return (kthNum(A, m, B, n, (m + n) / 2) + kthNum(A, m, B, n, (m + n) / 2 + 1)) / 2.0;
        }
    }
};