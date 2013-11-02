class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if(len1 + len2 != len3)
            return false;
        bool **f = new bool*[len1 + 1];
        for(int i = 0; i <= len1; ++i) {
            f[i] = new bool[len2 + 1];
            memset(f[i], 0, sizeof(bool) * (len2 + 1));
        }
        f[0][0] = true;
        for(int i = 1; i <= len1; ++i)
            f[i][0] = (f[i-1][0] && (s1[i-1] == s3[i-1]));
        for(int i = 1; i <= len2; ++i)
            f[0][i] = (f[0][i-1] && (s2[i-1] == s3[i-1]));
        for(int i = 1; i <= len1; ++i) {
            for(int j = 1; j <= len2; ++j) {
                f[i][j] = ((f[i-1][j] && (s1[i-1] == s3[i-1+j])) || (f[i][j-1] && (s2[j-1] == s3[i+j-1])));
            }
        }
        bool res = f[len1][len2];
        for(int i = 0; i <= len1; ++i)
            delete []f[i];
        delete []f;
        return res;
    }
};