class Solution { // almost the same as subsets.cpp, just almost ... not the same
public:
    vector<int> v;
    vector<vector<int> > vv;
    void compute(vector<int> &S, int index, bool lastChosen) {
        if(index >= S.size()) {
            vv.push_back(v);
            return;
        }
        compute(S, index + 1, false);
        if(index != 0 && S[index] == S[index - 1] && !lastChosen) {
            return;
        } else {
            v.push_back(S[index]);
            compute(S, index + 1, true);
            v.pop_back();
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        sort(S.begin(), S.end());
        v.clear(), vv.clear();
        compute(S, 0, true);
        return vv;
    }
};