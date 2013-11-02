class Solution {
public:
    char last;
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        const char *aster = NULL, *last = s;
        while(*s) {
            if(*p == *s || *p == '?') {
                ++s; ++p;
            } else if(*p == '*') {
                last = s;
                aster = p++;
            } else if(aster) {
                s = (++last);
                p = aster + 1;
            } else
                return false;
        }
        while(*p && *p == '*')
            ++p;
        return *p == '\0';
    }
};