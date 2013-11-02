class Solution {
public:
    int minDistance(string word1, string word2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int sz1 = word1.size(), sz2 = word2.size();
        int **f = new int*[sz1 + 1];
        for(int i = 0; i <= sz1; ++i) {
            f[i] = new int[sz2 + 1];
        }
        f[0][0] = 0;
        for(int i = 1; i <= sz1; ++i)
            f[i][0] = i;
        for(int j = 1; j <= sz2; ++j)
            f[0][j] = j;
        
        for(int i = 1; i <= sz1; ++i) {
            for(int j = 1; j <= sz2; ++j) {
                f[i][j] = min(min(f[i-1][j]+1, f[i][j-1]+1), word1[i-1]==word2[j-1]?f[i-1][j-1]:(f[i-1][j-1]+1));
            }
        }
        
        int res = f[sz1][sz2];
        for(int i = 0; i <= sz1; ++i)
            delete []f[i];
        delete []f;
        return res;
    }
};
