class Solution {
public:
    vector<vector<int> > vv;
    vector<int> v;
    int n;
    void recurse(int cur, int level) {
        if(level == 0) {
            vv.push_back(v);
            return;
        }
        for(int i = cur; i <= (n - level + 1); ++i) {
            v.push_back(i);
            recurse(i+1, level-1);
            v.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vv.clear(); v.clear();
        if(k > n)
            return vv;
        this->n = n;
        recurse(1, k);
        return vv;
    }
};
