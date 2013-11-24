/********************************************
 Solution 1: not a very efficient solution, yet it's an one-pass solution
 ********************************************/
class Solution {
public:
    void sortColors(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int indices[] = {0,n-1,n-1}; //indices[0] is never used ...
        for(int i = 0; i < n && i < indices[2]; ++i) {
            if(A[i] == 1) {
                if(i >= indices[1])
                    continue;
                indices[1] = min(indices[1], indices[2]);
                swap(A[i--], A[indices[1]--]);
            } else if(A[i] == 2) {
                swap(A[i--], A[indices[2]--]);
            }
        }
    }
};

/********************************************
 Solution 2: a better solution, from https://github.com/iphkwan/leetcode/blob/master/Sort_Colors.cc
 ********************************************/
class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = n - 1, cur = 0;
        while (cur <= right) {
            if (A[cur] == 0) {
                A[cur] = A[left] ;
                A[left++] = 0;
                if (left > cur) {
                    cur++;
                }
            } else if (A[cur] == 2) {
                A[cur] = A[right];
                A[right--] = 2;
            } else {
                cur++;
            }
        }
    }
};
