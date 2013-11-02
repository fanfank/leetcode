class Solution {
public:
    string itoa(int num) {
        char s[100];
        sprintf(s, "%d", num);
        return string(s);
    }
    string countAndSay(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int cnt, sz;
        char num;
        string s[2];
        int index = 0;
        s[0] = "1";
        for(int i = 2; i <= n; ++i) {
            index ^= 1;
            s[index].clear();
            sz = s[index^1].size();
            num = '#', cnt = 0;
            s[index^1].append(1, '\0');
            for(int j = 0; j <= sz; ++j)
                if(s[index^1][j] != num) {
                    if(num != '#') {
                        s[index].append(itoa(cnt));
                        s[index].append(1, num);
                    }
                    cnt = 1; num = s[index^1][j];
                } else {
                    cnt++;
                }
        }
        return s[index];
    }
};