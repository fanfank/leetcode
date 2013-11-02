class Solution {
public:
    vector<vector<int> > vv;
    vector<int> getRow(int rowIndex) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> v;
        if(rowIndex < vv.size())
            return rowIndex < 0?v:vv[rowIndex];
        if(vv.size() > 0)
            for(int i = 0; i < vv.back().size(); ++i)
                v.push_back((vv.back())[i]);
        for(int i = vv.size(); i <= rowIndex; ++i) {
            int last = 1;
            for(int j = 1; j < v.size(); ++j) {
                v[j] += last;
                last = v[j] - last;
            }
            v.push_back(1);
            vv.push_back(v);
        }
        return vv[rowIndex];
    }
};