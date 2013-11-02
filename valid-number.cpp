class Solution {
public:
    bool lastPosition(const char* &s, bool isStrict = false) {
        if(*s == '+' || *s == '-')
            s++;
        bool hasDot = false;
        bool hasChar = false;
        char last = '\0';
        while(*s) {
            if(*s == '.') {//a dot
                if(hasDot || isStrict)
                    return false;
                hasDot = true;
            } else if(*s == ' ') { //a space
                if(!hasChar)
                    return false;
                return true;
            } else if(isdigit(*s)){ //a digit
                hasChar = true;
            } else { //other characters
                if(*s == 'e') {
                    if(!hasChar)
                        return false;
                    return true;
                }
                return false;
            }
            last = *s;
            s++;
        }
        if(last == '\0' || !hasChar)
            return false;
        return true;
    }
    void trimSpace(const char* &s) {
        while(*s && *s == ' ')
            s++;
    }
    bool isNumber(const char *s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        trimSpace(s);
        bool f = lastPosition(s);
        //trimSpace(s);
        if(!f || (*s != 'e' && *s != '\0' && *s != ' '))
            return false;
        if(*s == 'e') {
            //trimSpace(++s);
            const char *temp = ++s;
            f = lastPosition(s, true);
            if(!f || *s == *temp)
                return false;
        }
        while(*s) {
            if(*s != ' ')
                return false;
            s++;
        }
        return true;
    }
}; // codes and problem itself are both very ugly