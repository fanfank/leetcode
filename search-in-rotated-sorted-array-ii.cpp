class Solution {
public:
    bool search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        for(int i = 0; i < n; ++i)
            if(A[i] == target)
                return true;
        return false;
    }
};