class Solution { 
public: 
    int findMin(vector<int> &num, int left, int right) { 
        if (num[left] < num[right] || left == right) { 
            return num[left]; 
        } 

        int middle = left + (right - left) / 2; 
        if (num[middle] < num[left]) { 
            return findMin(num, left, middle); 
        } else if (num[middle] > num[left]) { 
            return findMin(num, middle + 1, right); 
        } else if (num[middle] == num[left]) { 
            if (num[left] > num[right]) { 
                return findMin(num, middle + 1, right); 
            } else if (num[left] == num[right]) { 
                return min(findMin(num, left, middle), findMin(num, middle + 1, right)); 
            } else if (num[left] < num[right]) {/* impossible */} 
        } 
    }

    int findMin(vector<int> &num) { 
        return findMin(num, 0, num.size() - 1); 
    } 
};
