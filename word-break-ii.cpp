class Solution {
public:
    vector<string> v;
    void checkString(vector<vector<int> > &vv, int index, string s, const string &str) {
        for(int j = 0; j < vv[index].size(); ++j) {
            if(vv[index][j] == -1) {
                v.push_back(str.substr(0, index + 1) + s);
            } else {
                checkString(vv, vv[index][j], " " + str.substr(vv[index][j] + 1, index - vv[index][j]) + s, str);
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<vector<int> > vv(s.size()); //vv[i] stores indice after which to i makes a dict word, e.g. s[vv[i][j] + 1, i] is in dict
        for(int i = 0; i < s.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(vv[j].empty())
                continue;
                if(dict.find(s.substr(j+1, i-j)) != dict.end()) //substr(start position, number of characters)
                vv[i].push_back(j);
            }
            if(dict.find(s.substr(0, i+1)) != dict.end())
            vv[i].push_back(-1);
        }
        v.clear();
        checkString(vv, s.size() - 1, "", s);
        return v;
    }
};
