class Solution {
public:
    int roman[256] = {0};
    void setRoman() {
        if(roman[0])
            return;
        roman['i'] = roman['I'] = 1; roman['v'] = roman['V'] = 5; roman['x'] = roman['X'] = 10;
        roman['l'] = roman['L'] = 50; roman['c'] = roman['C'] = 100; roman['d'] = roman['D'] = 500;
        roman['m'] = roman['M'] = 1000; roman[0] = 1;
    }
    int romanToInt(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        setRoman();
        int sz = s.size(), ans = 0, last = 11111;
        for(int i = 0; i < sz; ++i) {
            ans += roman[s[i]];
            if(roman[s[i]] > last)
                ans -= 2 * last;
            last = roman[s[i]];
        }
        return ans;
    }
};