class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int add = 1;
        for(int i = digits.size() - 1; i >= 0; --i) {
            digits[i] += add;
            if(digits[i] > 9) {
                digits[i] -= 10;
            } else {
                add = 0;
                break;
            }
        }
        vector<int> v;
        if(add)
            v.push_back(1);
        for(int i = 0; i < digits.size(); ++i)
            v.push_back(digits[i]);
        return v;
    }
};