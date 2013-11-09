/******************************************
 solution 1 : an O(m+n) space solution
 ******************************************/
class Solution { // an O(m+n) space solution, not the best, see the second one
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        set<int> rwset, clset;
        int rw = matrix.size();
        int cl = 0;
        if(rw != 0)
            cl = matrix[0].size();
        for(int i = 0; i < rw; ++i)
            for(int j = 0; j < cl; ++j)
                if(matrix[i][j] == 0) {
                    rwset.insert(i);
                    clset.insert(j);
                }
        for(int i = 0; i < rw; ++i)
            if(rwset.find(i) != rwset.end()) {
                for(int j = 0; j < cl; ++j)
                    matrix[i][j] = 0;
            }
        for(int j = 0; j < cl; ++j)
            if(clset.find(j) != clset.end()) {
                for(int i = 0; i < rw; ++i)
                    matrix[i][j] = 0;
            }
    }
};

/******************************************
  solution 2 : a constant space solution
 ******************************************/
class Solution { // a constant space solution
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        bool frz = false, fcz = false;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                if(matrix[i][j] == 0) {
                    if(i == 0)
                        frz = true;
                    if(j == 0)
                        fcz = true;
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); ++i)
            if(matrix[i][0] == 0) {
                for(int j = 0; j < matrix[i].size(); ++j)
                    matrix[i][j] = 0;
            }
        for(int j = 1; j < matrix[0].size(); ++j)
            if(matrix[0][j] == 0) {
                for(int i = 1; i < matrix.size(); ++i)
                    matrix[i][j] = 0;
            }
        if(fcz)
            for(int i = 0; i < matrix.size(); ++i)
                matrix[i][0] = 0;
        if(frz)
            for(int j = 0; j < matrix[0].size(); ++j)
                matrix[0][j] = 0;
    }
};


