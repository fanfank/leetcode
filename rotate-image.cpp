class Solution {
public:
    int sz;
    void rotateCircle(vector<vector<int> > &matrix, int index) {
        int boundary = sz - 1 - index;
        for(int i = index; i < boundary; ++i) {
            int tmp = matrix[index][i], gap = i - index;
            swap(tmp, matrix[i][boundary]);
            swap(tmp, matrix[boundary][boundary - gap]);
            swap(tmp, matrix[boundary - gap][index]);
            swap(tmp, matrix[index][i]);
        }
    }
    void rotate(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        sz = matrix.size();
        for(int i = 0; i < sz / 2; ++i) {
            rotateCircle(matrix, i);
        }
    }
};