class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        map<int, int> m;
        int sz = numbers.size();
        for(int i = 0; i < sz; ++i) {
            map<int, int>::iterator p = m.find(target - numbers[i]);
            if(p != m.end()) {
                return vector<int>({p->second + 1, i + 1});
            }
            m[numbers[i]] = i;
        }
    }
};