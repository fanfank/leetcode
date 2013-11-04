class Solution {
public:
    string convert(string s, int nRows) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(nRows <= 1)
            return s;
        int sz = s.size();
        string res = "";
        for(int i = 0; i < nRows; ++i) {
            int st = i, gap = 2*nRows - 2;
            if(i == 0 || i == nRows - 1) {
                while(st < s.size()) {
                    res.append(1, s[st]);
                    st += gap;
                }
            } else {
                int st2 = 2 * (nRows - 1) - i;
                while(st < s.size() || st2 < s.size()) {
                    if(st < s.size()) {
                        res.append(1, s[st]);
                        st += gap;
                    }
                    if(st2 < s.size()) {
                        res.append(1, s[st2]);
                        st2 += gap;
                    }
                }
            }
        }
        return res;
    }
};