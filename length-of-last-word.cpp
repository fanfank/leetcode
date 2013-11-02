class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int cnt = 0, maxcnt = 0;
        while(*s) {
            if(*s == ' ') {
                cnt = 0;
            } else {
                cnt++;
                maxcnt = cnt;
            }
            s++;
        }
        maxcnt = cnt > 0?cnt : maxcnt;
        return maxcnt;
    }
};