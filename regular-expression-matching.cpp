/*****************************
 Solution 1: very ugly codes
 *****************************/
class Solution {
public:
    struct node {
        const char *spos, *ppos;
        node(const char *sp, const char *pp) : spos(sp), ppos(pp) {}
    };
    bool isMatch(const char *s, const char *p) {
        stack<node> sta;
        bool f = false;
        while(true) {
            if(*s == 0 && *p == 0) {
                f = true;
                break;
            }
            if(*p && *(p+1) == '*') {
                if(*s)
                    sta.push(node(s, p));
                p = p + 2;
            } else {
                bool solved = true;
                while(*s == '\0' || (*p != '.' && *p != *s)) {
                    solved = false;
                    if(sta.empty())
                        break;
                    node tmp = sta.top();
                    sta.pop();
                    s = tmp.spos;
                    p = tmp.ppos + 1;
                    if(*(tmp.ppos) == '.' || *(tmp.spos) == *(tmp.ppos)) {
                        if(*(tmp.spos + 1))
                            sta.push(node(tmp.spos + 1, tmp.ppos));
                        solved = true;
                        break;
                    }
                }
                if(solved) {
                    ++s, ++p;
                } else {
                    break;
                }
            }
        }
        return f;
    }
};

/************************************************************
 Solution 2: recursion method, good one. from iphkwan@github
 ************************************************************/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (*p == '\0') {
            return (*s == '\0');
        }
        if (*(p + 1) == '*') {
            while ((*p == '.' && *s != '\0') || *s == *p) {
                if (isMatch(s, p + 2)) {
                    return true;
                }
                s++;
            }
            return isMatch(s, p + 2);
        } else {
            if ((*p == '.' && *s != '\0') || *s == *p) {
                return isMatch(s + 1, p + 1);
            }
            return false;
        }
    }
};