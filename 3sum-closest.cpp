class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        sort(num.begin(), num.end());
        int sz = num.size(), res = 0, abso = 0x7fffffff;
        for(int i = 0; i < sz - 1; ++i) {
            if(i > 0 && num[i] == num[i-1])
                continue;
            int lp = i + 1, rp = sz - 1;
            while(lp < rp) {
                int sum = num[i] + num[lp] + num[rp];
                if(sum == target)
                    return target;
                if(abs(sum - target) < abso) {
                    res = sum;
                    abso = abs(sum - target);
                }
                if(sum > target) {
                    int tmp = num[rp];
                    while(lp < --rp && num[rp] == tmp);
                } else {
                    int tmp = num[lp];
                    while(++lp < rp && num[lp] == tmp);
                }
            }
        }
        return res;
    }
};