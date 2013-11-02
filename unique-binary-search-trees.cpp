class Solution {
public:
    vector<int> v;
    int numTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n < v.size())
            return v[n];
        for(int i = v.size(); i <= n; ++i) {
            if(0 == i || 1 == i)
                v.push_back(1);
            else {
                int j = 0;
                v.push_back(0);
                for(; j < i / 2; ++j)
                    v[i] += 2 * v[j] * v[i-1-j];
                if(i & 1)
                    v[i] += v[j] * v[j];
            }
        }
        return v[n];
    }
};