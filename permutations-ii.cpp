class Solution { //almost the same as permutations.cpp
public:
    int sz;
    vector<vector<int> > vv;
    void permutation(vector<int> &v, int left, int right) {
        if(left == right) {
            vv.push_back(v);
            return;
        }
        permutation(v, left + 1, right);
        set<int> s;
        s.insert(v[left]);
        for(int i = left + 1; i <= right; ++i) {
            if(s.find(v[i]) == s.end())
                s.insert(v[i]);
            else
                continue;
            swap(v[left], v[i]);
            permutation(v, left + 1, right);
            swap(v[left], v[i]);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vv.clear();
        sz = num.size();
        if(sz > 0)
            permutation(num, 0, sz - 1);
        return vv;
    }
};