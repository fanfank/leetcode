class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(matrix.size() < 1 || matrix[0].size() < 1)
            return false;
        int i = 0, j = matrix[0].size() - 1;
        while(i < matrix.size() && j >= 0) {
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] < target)
                i++;
            else
                j--;
        }
        return false;
    }
};