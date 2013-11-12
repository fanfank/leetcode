class Solution {
public:
    vector<vector<string> > vv;
    vector<vector<int> > ispal;
    int sz;
    vector<vector<string> > partition(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ispal.clear();
        sz = s.size();
        for(int i = 0; i < sz; ++i) {
            ispal.push_back(vector<int>(sz));
            ispal[i][i] = true;
        }
        for(int i = 1; i < sz; ++i) {
            for(int j = 0; i+j < sz; ++j) {
                ispal[j][i+j] = (i+j>j+1)?ispal[j+1][i+j-1]&&s[j]==s[i+j]:s[j]==s[i+j];
            }
        }
        vv.clear();
        vector<string> helper;
        dfs(0, s, helper);
        return vv;
    }
    void dfs(int index, string &s, vector<string> &helper) {
        if(index >= sz) {
            vv.push_back(helper);
            return;
        }
        for(int j = 0; index+j < sz; ++j) {
            if(ispal[index][index+j]) {
                helper.push_back(s.substr(index, j+1));
                dfs(index+j+1, s, helper);
                helper.pop_back();
            }
        }
    }
};