class Solution {
public:
    int binarySearch(int a[], int left, int right, int target) {
        while(left < right) {
            int middle = left + (right - left) / 2;
            if(a[middle] == target)
                return middle;
            else if(a[middle] < target)
                left = middle + 1;
            else
                right = middle;
        }
        if(target > a[left])
            return left + 1;
        return left;
    }
    int searchInsert(int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n <= 0)
            return 0;
        return binarySearch(A, 0, n - 1, target);
    }
};