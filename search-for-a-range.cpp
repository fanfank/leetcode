class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v;
        if(n == 0)
        {
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        v.push_back(binarySearchLow(A,0,n-1,target));
        v.push_back(binarySearchHigh(A,0,n-1,target));
        return v;
    }
private:
    int binarySearchLow(int a[], int left, int right, int k)
    {
        if(k < a[left] || k > a[right])
            return -1;
        int middle;
        while(left < right)
        {
            middle = left + (right - left) / 2;
            if(a[middle] < k)
                left = middle + 1;
            else if(a[middle] > k)
                right = middle - 1;
            else
                right = middle;
        }
        if(a[left] == k)
            return left;
        else
            return -1;
    }
    int binarySearchHigh(int a[], int left, int right, int k)
    {
        if(k < a[left] || k > a[right])
            return -1;
        int middle;
        while(left < right)
        {
            middle = left + (right - left) / 2 + 1;
            if(a[middle] < k)
                left = middle + 1;
            else if(a[middle] > k)
                right = middle - 1;
            else
                left = middle;
        }
        if(a[left] == k)
            return left;
        else
            return -1;
    }
};
