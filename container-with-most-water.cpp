class Solution {
public:
    int maxArea(vector<int> &height) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int lp = 0, rp = height.size() - 1;
        int res = 0;
        while(lp < rp) {
            res = max(res, (rp - lp) * min(height[lp], height[rp]));
            if(height[lp] < height[rp]) {
                int tmp = height[lp];
                while( (++lp) < rp && height[lp] <= tmp);
            } else {
                int tmp = height[rp];
                while( (--rp) > lp && height[rp] <= tmp);
            }
        }
        return res;
    }
};