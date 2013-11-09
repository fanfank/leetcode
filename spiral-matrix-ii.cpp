class Solution {
public:
    void getCircle(vector<vector<int> > &vv, int index, int &cnt, const int &n) {
        if(index * 2 == (n - 1)) {
            vv[index][index] = cnt++;
            return;
        }
        int i = index, j = index, stx = index, sty = index, edx = n - index - 1, edy = n - index - 1;
        while(j <= edy)
            vv[i][j++] = cnt++;
        j--; i++;
        
        while(i <= edx)
            vv[i++][j] = cnt++;
        i--; j--;
        
        while(j >= sty)
            vv[i][j--] = cnt++;
        j++; i--;
        
        while(i > stx)
            vv[i--][j] = cnt++;
    }
    vector<vector<int> > generateMatrix(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > vv;
        for(int i = 0; i < n; ++i)
            vv.push_back(vector<int>(n));
        int cnt = 1, index = 0, target = n * n;
        while(cnt <= target) {
            getCircle(vv, index, cnt, n);
            index++;
        }
        return vv;
    }
};