class Solution {//almost the same as n-queens.cpp
public:
    int ans;
    void setVisited(vector<vector<int> > &vvi, int x, int y, int n, int value) {
        for(int i = x + 1; i < n; ++i) { //down
            vvi[i][y] += value;
        }
        for(int i = x + 1, j = y + 1; i < n && j < n; ++i, ++j) { //downright
            vvi[i][j] += value;
        }
        for(int i = x + 1, j = y - 1; i < n && j >= 0; ++i, --j) { //downleft
            vvi[i][j] += value;
        }
    }
    void dfs(vector<vector<int> > &vvi, const int depth, const int n) {
        if(depth == n) {
            ++ans;
            return;
        }
        for(int i = 0; i < n; ++i) {
            if(vvi[depth][i])
                continue;
            setVisited(vvi, depth, i, n, 1);
            dfs(vvi, depth+1, n);
            setVisited(vvi, depth, i, n, -1);
        }
    }
    int totalNQueens(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ans = 0;
        vector<vector<int> > vvi;
        for(int i = 0; i < n; ++i) {
            vvi.push_back(vector<int>(n, 0));
        }
        dfs(vvi, 0, n);
        return ans;
    }
};