class Solution {
public:
    int numDistinct(string S, string T) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> v(T.size(), 0);
        vector<vector<int> > vv(256);
        for(int i = 0; i < T.size(); ++i) {
            vv[T[i]].push_back(i);
        }
        for(int i = 0; i < S.size(); ++i) {
            if(vv[S[i]].empty())
                continue;
            int sz = vv[S[i]].size();
            for(int j = sz - 1; j >= 0; --j) {
                int index = vv[S[i]][j];
                if(index == 0) {
                    ++v[index];
                } else {
                    v[index] += v[index-1];
                }
            }
        }
        return T.size()?v.back():0;
    }
};