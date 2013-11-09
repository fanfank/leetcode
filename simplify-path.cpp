class Solution { //stack doesn't have an iterator
public:
    string simplifyPath(string path) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        deque<string> s;
        int sz = path.size(), i = 0;
        while(i < sz) {
            while(i < sz && path[i] == '/')
                ++i;
            if(i >= sz)
                break;
            int j = i;
            while(j < sz && path[j] != '/')
                ++j;
            string tmp = path.substr(i, j - i);
            if(tmp == "..") {
                if(!s.empty())
                    s.pop_back();
            } else if(tmp != ".")
                s.push_back(tmp);
            i = j;
        }
        string res = "";
        if(!s.empty())
            for(deque<string>::iterator p = s.begin(); p != s.end(); ++p)
                res += ("/" + *p);
        else
            res = "/";
        return res;
    }
};