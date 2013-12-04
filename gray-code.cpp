class Solution {
public:
    vector<int> grayCode(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n == 0)
            return vector<int>({0});
        int cnt = 1;
        vector<int> v({0, 1});
        while(n > cnt) {
            int index = v.size() - 1, basis = (v.back() << 1);
            while(index >= 0)
                v.push_back(basis | v[index--]);
            ++cnt;
        }
        return v;
    }
};