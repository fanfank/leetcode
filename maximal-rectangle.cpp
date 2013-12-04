/************************************************
 Solution 1: m*n matrix, takes O(n) space
 ************************************************/
class Solution {//similar to "largest rectangle in histogram"
public:
    struct node {
        int index, ceiling;
        node(int i, int h) : index(i), ceiling(h) {}
    };
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty())
            return 0;
        int res = 0, row = matrix.size(), col = matrix[0].size();
        vector<int> height(col, 0);
        stack<node> boundary;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                height[j] = matrix[i][j]=='1'?height[j]+1:0;
                int lastindex = j;
                while(!boundary.empty() && height[j] <= boundary.top().ceiling) {
                    lastindex = boundary.top().index;
                    res = max(res, boundary.top().ceiling * (j - boundary.top().index));
                    boundary.pop();
                }
                boundary.push(node(lastindex, height[j]));
            }
            while(!boundary.empty()) {
                res = max(res, boundary.top().ceiling * (col - boundary.top().index));
                boundary.pop();
            }
        }
        return res;
    }
};

/****************************************************
 Solution 2: traditional method, takes O(m*n) space
 ****************************************************/
class Solution {//"traditional" method
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        vector<vector<int> > vv;
        for(int i = 0; i < matrix.size(); ++i) {
            vv.push_back(vector<int>(matrix[0].size(), 0));
            for(int j = 0; j < matrix[0].size(); ++j) {
                vv[i][j] = (matrix[i][j]=='1')?1:0;
                if(j > 0 && vv[i][j] > 0)
                    vv[i][j] += vv[i][j-1];
            }
        }
        int res = 0;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                int minLength = 0x7fffffff;
                for(int k = i; k >= 0 && minLength > 0; --k) {
                    minLength = min(minLength, vv[k][j]);
                    res = max(res, minLength * (i - k + 1));
                }
            }
        }
        return res;
    }
};