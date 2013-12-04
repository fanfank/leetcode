/********************************************************************
 Solution 1: this code can be compressed to solution 2
             这段代码可以进一步简化，变成方法2中的样子，不过方法1的容易懂一点
 ********************************************************************/
class Solution {
public:
    int delta(int &num, int delta) {
        int ret = 0;
        if(num == 0)
            ret = 1;
        if(num + delta == 0)
            ret = -1;
        num += delta;
        return ret;
    }
    bool isScramble(string s1, string s2) {
        if(s1.size() == 1)
            return s1 == s2;
        vector<int> v(256, 0);
        bool f = false;
        int p1 = 0, p2 = 0, sz = s1.size(), count = 0;
        while(p1 < sz) {
            count += delta(v[s1[p1++]], 1);
            count += delta(v[s2[p2++]], -1);
            if(count == 0)
                break;
        }
        if(p1 < sz) {
            f = isScramble(s1.substr(0, p1), s2.substr(0, p2)) && isScramble(s1.substr(p1), s2.substr(p2));
            if(f)
                return true;
        }
        p1 = 0, p2 = sz, count = 0;
        for(int i = 0; i < v.size(); ++i)
            v[i] = 0;
        while(p1 < sz) {
            count += delta(v[s1[p1++]], 1);
            count += delta(v[s2[--p2]], -1);
            if(count == 0)
                break;
        }
        if(p1 < sz) {
            f = isScramble(s1.substr(0, p1), s2.substr(p2)) && isScramble(s1.substr(p1), s2.substr(0, p2));
        }
        return f;
    }
};

/********************************************************************
 Solution 2: a compressed version of solution 1
             方法1经过代码一些整理后就变成下面的代码了
 ********************************************************************/
class Solution {
public:
    int delta(int &num, int delta) {
        int ret = 0;
        if(num == 0)
            ret = 1;
        if(num + delta == 0)
            ret = -1;
        num += delta;
        return ret;
    }
    bool checkString(string s1, string s2, int p2, int dp2) {
        int p1 = 0, sz = s1.size(), count = 0;
        vector<int> v(256, 0);
        while(p1 < sz) {
            count += delta(v[s1[p1]], 1);
            count += delta(v[s2[p2]], -1);
            p1 = p1 + 1;
            p2 = p2 + dp2;
            if(count == 0)
                break;
        }
        if(p1 < sz) {
            if(dp2 > 0)
                return isScramble(s1.substr(0, p1), s2.substr(0, p2)) && isScramble(s1.substr(p1), s2.substr(p2));
            else
                return isScramble(s1.substr(0, p1), s2.substr(p2 + 1)) && isScramble(s1.substr(p1), s2.substr(0, p2 + 1));
        }
        return false;
    }
    bool isScramble(string s1, string s2) {
        if(s1.size() == 1)
            return s1 == s2;
        return checkString(s1, s2, 0, 1) || checkString(s1, s2, s2.size() - 1, -1);
    }
};