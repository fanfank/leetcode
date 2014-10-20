class Solution {
public:
	int findMin(vector<int> &num, int left, int right) {
		if (left == right || num[left] < num[right]) {
			return num[left];
		}
		int middle = left + (right - left) / 2;
		if (num[middle] < num[left]) {
			return findMin(num, left, middle);
		} else if (num[middle] >= num[left]) {
			return findMin(num, middle + 1, right);
		}	
	}
    int findMin(vector<int> &num) {
		return findMin(num, 0, num.size() - 1);
    }
};
