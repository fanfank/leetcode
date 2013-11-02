//Though this is an O(Nlog(N)) method, it passes...
//O(N) method may be that: use unordered_set, and scan from 1 to 0x7fffffff
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size() == 0)
            return 0;
        
        set<int> s;
        for(int i = 0; i < num.size(); ++i)
            s.insert(num[i]);
        
        set<int>::iterator p = s.begin();
        int ans = 0, cnt = 1, last = *p;
        while(++p != s.end())
        {
            if(*p == last + 1)
            {
                ++cnt;
            }
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
            }
            last = *p;
        }
        ans = max(ans, cnt);
        return ans;
    }
};
