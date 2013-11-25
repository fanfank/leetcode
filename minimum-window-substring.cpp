class Solution {
public:
    string minWindow(string S, string T) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> count(256, 0), cur_count(256, 0);
        int lp = -1, rp = -1, ans = 0x7fffffff, lb = 0, lack = T.size();
        for(int i = 0; i < T.size(); ++i)
            ++count[T[i]];
        for(int i = 0; i < S.size(); ++i) {
            if(cur_count[S[i]] < count[S[i]])
                --lack;
            ++cur_count[S[i]];
            if(lack == 0) {
                while(lb <= i && (cur_count[S[lb]] - 1 >= count[S[lb]])) {
                    --cur_count[S[lb]];
                    ++lb;
                }
                if(ans > i - lb + 1) {
                    ans = i - lb + 1;
                    lp = lb;
                    rp = i;
                }
                while(lb <= i && lack == 0) {
                    --cur_count[S[lb]];
                    if(cur_count[S[lb]] < count[S[lb]]) {
                        ++lack;
                    }
                    ++lb;
                }
            }
        }
        return lp == -1?"":S.substr(lp, rp - lp + 1);
    }
};