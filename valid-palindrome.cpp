class Solution {
public:
    char isAlpha(char c)
    {
        if( (c>='0' && c<='9') || (c>='a' && c<='z') || (c>='A' && c<='Z'))
            return true;
        return false;
    }
    char toLower(char c)
    {
        if(c>='A' && c<='Z')
            return (c+('a'-'A'));
        return c;
    }
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size() == 0)
            return true;
        string ss;
        for(int i = 0; i < s.size(); i++)
        {
            if(isAlpha(s[i]))
            {
                ss.append(1, toLower(s[i]));
            }
        }
        int bg = 0; int ed = ss.size() - 1;
        while(bg<ed)
        {
            if(ss[bg] != ss[ed])
                return false;
            bg++; ed--;
        }
        return true;
    }
};
