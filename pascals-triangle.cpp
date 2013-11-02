class Solution {
public:
    vector<vector<int> > vv;
    vector<vector<int> > generate(int numRows) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vv.clear();
        vector<int> v;
        for(int i = 1; i <= numRows; ++i) {
            int last = 1;
            for(int j = 1; j < v.size(); ++j) {
                v[j] += last;
                last = v[j] - last;
            }
            v.push_back(1);
            vv.push_back(v);
        }
        return vv;
    }
};