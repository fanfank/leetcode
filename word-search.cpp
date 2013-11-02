class Solution {
private:
    int row, col, dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
    
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(0 == word.size())
            return true;
        
        row = board.size();
        col = board[0].size();
        char *str = new char[word.size() + 1];
        strcpy(str, word.c_str());
        
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++) {
                if(str[0] == board[i][j]) {
                    board[i][j] = '#';
                    if(findString(board, i, j, str, 1)) {
                        delete str;
                        return true;
                    }
                    board[i][j] = str[0];
                }
            }
        delete str;
        return false;
    }
    bool findString(vector<vector<char> > &board, int r, int c, char *str, int pos) {
        if('\0' == str[pos])
            return true;
        
        for(int i = 0; i < 4; i++) {
            int tr = r + dr[i], tc = c + dc[i];
            if(isOk(tr, tc) && '#' != board[tr][tc] && str[pos] == board[tr][tc]) {
                board[tr][tc] = '#';
                if(findString(board, tr, tc, str, pos + 1))
                    return true;
                board[tr][tc] = str[pos];
            }
        }
        return false;
    }
    bool isOk(int r, int c) {
        if(r >= 0 && r < row && c >= 0 && c < col)
            return true;
        return false;
    }
};