class Solution {
public:
    vector<vector<string> > vvs;
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
    void dfs(vector<string> &vs, vector<vector<int> > &vvi, const int depth, const int n) {
        if(depth == n) {
            vvs.push_back(vs);
            return;
        }
        for(int i = 0; i < n; ++i) {
            if(vvi[depth][i])
                continue;
            setVisited(vvi, depth, i, n, 1);
            vs[depth][i] = 'Q';
            dfs(vs, vvi, depth+1, n);
            vs[depth][i] = '.';
            setVisited(vvi, depth, i, n, -1);
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vvs.clear();
        vector<string> vs;
        vector<vector<int> > vvi;
        for(int i = 0; i < n; ++i) {
            vs.push_back(string(n,'.'));
            vvi.push_back(vector<int>(n, 0));
        }
        dfs(vs, vvi, 0, n);
        return vvs;
    }
};