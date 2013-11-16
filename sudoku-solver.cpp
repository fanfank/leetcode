class Solution {
public:
    struct node {
        int rw, cl;
        node(int rr, int cc) : rw(rr), cl(cc) {}
    };
    int sz;
    vector<node> empty;
    bool dfs(vector<vector<char> > &grid, int depth) {
        if(depth >= sz)
            return true;
        int rw = empty[depth].rw, cl = empty[depth].cl;
        bool allow[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        for(int j = 0; j < 9; ++j) //check row
            if(grid[rw][j] != '.')
                allow[grid[rw][j] - '0'] = 0;
        for(int i = 0; i < 9; ++i) //check col
            if(grid[i][cl] != '.')
                allow[grid[i][cl] - '0'] = 0;
        for(int i = (rw/3)*3; i < (rw/3)*3 + 3; ++i) //check grid
            for(int j = (cl/3)*3; j < (cl/3)*3 + 3; ++j)
                if(grid[i][j] != '.')
                    allow[grid[i][j] - '0'] = 0;
        for(int i = 1; i <= 9; ++i) {
            if(!allow[i])
                continue;
            grid[rw][cl] = '0' + i;
            if(dfs(grid, depth + 1))
                return true;
            grid[rw][cl] = '.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char> > &board) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //sz = board.size();
        empty.clear();
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j)
                if(board[i][j] == '.')
                    empty.push_back(node(i,j));
        sz = empty.size();
        dfs(board, 0);
    }
};