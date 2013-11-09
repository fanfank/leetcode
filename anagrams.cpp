class Solution { //a very violent method
public:
    vector<string> anagrams(vector<string> &strs) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        map<string, vector<string> > m;
        vector<string> ans;
        for(int i = 0; i < strs.size(); ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(strs[i]);
        }
        for(map<string, vector<string> >::iterator p = m.begin(); p != m.end(); ++p) {
            if(p->second.size() > 1) {
                for(int i = 0; i < p->second.size(); ++i)
                    ans.push_back(p->second[i]);
            }
        }
        return ans;
    }
};