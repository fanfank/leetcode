/**************************************
 Solution 1: a bad solution
 **************************************/
class Solution {
public:
    const int MAX = 46340;
    int sqrt(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(x < 0)
            return 0;
        int left = 0, right = x;
        while(left < right - 1) {
            int middle = left + (right - left) / 2;
            if(middle > MAX) {
                right = middle;
                continue;
            }
            int num = middle * middle;
            if(num == x) {
                return middle;
            } else if(num < x) {
                left = middle;
            } else {
                right = middle;
            }
        }
        if(right <= MAX && right * right == x)
            return right;
        return left;
    }
};

/**************************************
 Solution 1: a good solution from https://github.com/iphkwan/leetcode/blob/master/Sqrt_x.cc
 **************************************/
class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = x, mid;
        while (left < right) {
            mid = left + (right - left) / 2 + 1;
            if (x / mid == mid) {
                return mid;
            } else if (x / mid < mid) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return right;
    }
};