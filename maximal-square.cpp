class Solution {
    struct Point {
        int left, up, area, side;
        Point() {
            this->side = this->area = this->left = this->up = 0;
        }
    };
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // Space: O(m), m = column number, use rolling array
        // Time: O(n)

        int row_num = matrix.size();
        if (row_num == 0) {
            return 0;
        }
        int col_num = matrix[0].size();
        if (col_num == 0) {
            return 0;
        }
        vector<Point> v(col_num);

        int ans = 0;
        Point upPoint, lastCrossPoint, nullPoint;
        for (int i = 0; i < row_num; ++i) {
            for (int j = 0; j < col_num; ++j) {
                if (i > 0) {
                    upPoint = v[j];
                }
                
                if (matrix[i][j] == '0') {
                    v[j] = nullPoint;
                    lastCrossPoint = upPoint;
                    continue;
                }
                
                // Accumulate left
                if (j > 0) {
                    v[j].left = v[j-1].left + 1;
                } else {
                    v[j].left = 1;
                }

                // Accumulate up
                if (i > 0) {
                    v[j].up = v[j].up + 1;
                } else {
                    v[j].up = 1;
                }

                // compute area
                v[j].area = v[j].side = 1;
                if (i == 0 || j == 0) {
                    v[j].area = v[j].side = 1;

                } else if (lastCrossPoint.area > 0) {
                    int left_bound = min(lastCrossPoint.side + 1, v[j].left);
                    int up_bound = min(lastCrossPoint.side + 1, v[j].up);

                    v[j].side = min(left_bound, up_bound);
                    v[j].area = v[j].side * v[j].side;
                }

                ans = max(v[j].area, ans);
                lastCrossPoint = upPoint;
            }
        }

        return ans;
    }
};
