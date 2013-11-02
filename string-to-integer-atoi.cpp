class Solution {
public:
    const long long MAX = ((int)0x7fffffff);
    const long long MIN = ((int)0x80000000);
    int atoi(const char *str) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        while(*str && *str == ' ')
            str++;
        bool isMinus = false;
        if(*str == '-') {
            isMinus = true, str++;
        } else if(*str == '+') {
            str++;
        }
        long long ans = 0;
        while(*str) {
            if(isdigit(*str)) {
                ans = ans * 10 + (*str - '0');
                if(isMinus && (-ans <= MIN))
                    return MIN;
                if(!isMinus && (ans >= MAX))
                    return MAX;
            } else {
                break;
            }
            str++;
        }
        if(isMinus)
            ans *= -1;
        return ans;
    }
};