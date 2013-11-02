class Solution {
public:
    bool b[10];
    bool checkRowCol(vector<vector<char> > &board, int x, int y, int dx, int dy) {
        memset(b, false, sizeof(b));
        for(int i = 1; i <= 9; ++i, x += dx, y += dy) {
            if(!isdigit(board[x][y]))
                continue;
            if(b[board[x][y] - '0'])
                return false;
            b[board[x][y] - '0'] = true;
        }
        return true;
    }
    bool checkBox(vector<vector<char> > &board, int x, int y) {
        memset(b, false, sizeof(b));
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j) {
                if(!isdigit(board[x+i][y+j]))
                    continue;
                if(b[board[x+i][y+j] - '0'])
                    return false;
                b[board[x+i][y+j] - '0'] = true;
            }
        return true;
    }
    bool isValidSudoku(vector<vector<char> > &board) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        for(int i = 0; i < 9; ++i) {
            if(!checkRowCol(board, i, 0, 0, 1)) return false;
            if(!checkRowCol(board, 0, i, 1, 0)) return false;
        }
        for(int i = 0; i < 9; i += 3)
            for(int j = 0; j < 9; j += 3)
                if(!checkBox(board, i, j))
                    return false;
        return true;
    }
};