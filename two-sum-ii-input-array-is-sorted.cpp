class Solution {
public:
    int buSearch(vector<int>& a, int left, int right, int target) {
        while (left < right) {
            int mid = left + (right - left) / 2 + 1;
            if (a[mid] > target) {
                right = mid - 1;
            } else if (a[mid] < target) {
                left = mid;
            } else {
                return mid;
            }
        }
        return right;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        // Use upper binary search
        // Find the last element that is <= target - x
        
        vector<int> ans;
        int lastRight = numbers.size() - 1;
        for (int i = 0; i < numbers.size(); ++i) {
            int y = target - numbers[i];
            int right = this->buSearch(numbers, i, lastRight, y);
            if (right <= i) {
                break;
            }
            if (numbers[right] == y) {
                ans.push_back(i+1);
                ans.push_back(right+1);
                return ans;
            }
            lastRight = right;
        }
        return ans;
    }
};
