class Solution {
public:
    int binarySearch(int a[], int l, int r, int k) {
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(a[m] == k)
                return m;
            else if(a[m] < k)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
    int search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int l = 0, r = n - 1, p;
        
        //find max point
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(A[l] > A[r]) {
                if(A[l] < A[m])
                    l = m;
                else
                    r = m;
            } else {
                p = r;
                break;
            }
        }
        
        int res = binarySearch(A, 0, p, target);
        if(res != -1)
            return res;
        if(p + 1 < n)
            return binarySearch(A, p + 1, n - 1, target);
        return -1;
    }
};