class Solution {
public:
    vector<vector<int> > vv;
    void dfs(vector<int> &v, int index, const int &target, int sum, vector<int> &helper) {
        if(index >= v.size() || v[index] > target)
            return;
        int sz = v.size();
        for(int i = index; i < sz; ++i) {
            if(i != index && v[i] == v[i-1])
                continue;
            sum += v[i];
            if(sum > target)
                return;
            helper.push_back(v[i]);
            if(sum == target)
                vv.push_back(helper);
            dfs(v, i, target, sum, helper);
            helper.pop_back();
            sum -= v[i];
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vv.clear();
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, 0, v);
        return vv;
    }
};