class Solution {
public:
    int pos[256];
    int lengthOfLongestSubstring(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        for(int i = 0; i < 256; ++i)
            pos[i] = -1;
        int stp = -1, sz = s.size(), res = 0;
        for(int i = 0; i < sz; ++i) {
            if(pos[s[i]] >= stp) {  //update posistion
                stp = pos[s[i]] + 1;
            }
            pos[s[i]] = i;
            res = max(res, i - stp + 1);
        }
        return res;
    }
};//whose code is shorter than mine? Please notify me! I want to meet shorter codes!