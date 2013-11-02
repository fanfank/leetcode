class Solution {
public:
    vector<string> v;
    void handle(const string s, const string res, const int level)
    {
        if(level == 4 && s == "")
        {    
            v.push_back(res);
            return;
        }
        int sz = s.size();
        int left = 4 - level;
        if(sz < left || sz > left * 3)
            return;
        int mini = (sz-(left-1)*3>0?sz-(left-1)*3:1);
        int maxi = (sz-(left-1)>3?3:sz-(left-1));
        
        string stmp;
        for(int i = mini; i <= maxi; ++i)
        {
            if(s[0] == '0' && i > 1)
                break;
                
            stmp = s.substr(0, i);
            int num = atoi(stmp.c_str());
            if(num > 255)
                break;
            
            if(level == 3)
                handle(s.substr(i), res + stmp, level + 1);
            else
                handle(s.substr(i), res + stmp + ".", level + 1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        v.clear();
        for(int i = 0; i < s.size(); ++i)
            if(!(s[i] >= '0' && s[i] <= '9'))
                return v;
        
        string res = "";
        handle(s, res, 0);
        return v;
    }
};
