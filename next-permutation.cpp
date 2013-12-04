/************************************************
 Solution 1: shorter than solution 2
 ************************************************/
class Solution {
public:
    int binarySearchLarge(vector<int> &v, int left, int right, int target) {
        while(left < right) {
            int middle = left + (right - left + 1) / 2; //get ceiling
            if(v[middle] <= target)
                right = middle - 1;
            else
                left = middle;
        }
        if(v[left] <= target)
            return -1;
        else
            return left;
    }
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i = num.size() - 2; i >= 0; --i) {
            int index = binarySearchLarge(num, i + 1, num.size() - 1, num[i]);
            if(index != -1) {
                swap(num[index], num[i]);
                reverse(num.begin() + i + 1, num.end());
                return;
            }
        }
        reverse(num.begin(), num.end());
    }
};

/************************************************
 Solution 2: another method
 ************************************************/
class Solution {
public:
    int binarySearchLarge(vector<int> &v, int left, int right, int target) {
        while(left < right) {
            int middle = left + (right - left + 1) / 2; //get ceiling
            if(v[middle] <= target)
                right = middle - 1;
            else
                left = middle;
        }
        if(v[left] <= target)
            return -1;
        else
            return left;
    }
    bool permute(vector<int> &v, int left, int right) {
        if(left >= right) {
            return false;
        }
        if(permute(v, left + 1, right)) {
            return true;
        } else {
            int index = binarySearchLarge(v, left + 1, right, v[left]);
            if(index == -1) {
                return false;
            } else {
                swap(v[left], v[index]);
                reverse(v.begin() + left + 1, v.end());
                return true;
            }
        }
    }
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!permute(num, 0, num.size() - 1))
            reverse(num.begin(), num.end());
    }
};