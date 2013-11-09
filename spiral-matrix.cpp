class Solution {//extremely ugly code, the definitions of my parameters are misleading
public:
    vector<int> v;
    int rw, cl;
    struct node {
        int x, y;
        node(int xx = 0, int yy = 0) : x(xx), y(yy){}
    };
    void printCircle(vector<vector<int> > &vv, node upperLeft, node lowerRight) {
        int i = upperLeft.x, j = upperLeft.y;
        for(; j < lowerRight.y; ++j)
            v.push_back(vv[i][j]);
        j--; i++;
        
        for(; i < lowerRight.x; ++i)
            v.push_back(vv[i][j]);
        i--; j--;
        
        for(; j >= upperLeft.y && i > upperLeft.x; --j)
            v.push_back(vv[i][j]);
        j++; i--;
        
        if((upperLeft.y + 1) != lowerRight.y)
            for(; i > upperLeft.x; --i)
                v.push_back(vv[i][j]);
    }
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        v.clear();
        if(matrix.size() < 1 || matrix[0].size() < 1)
            return v;
        rw = matrix.size(), cl = matrix[0].size();
        int index = 0;
        while(index <= (rw - 1) / 2 && index <= (cl - 1) / 2) {
            printCircle(matrix, node(index, index), node(rw - index, cl - index));
            index++;
        }
        return v;
    }
};