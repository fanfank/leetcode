class Solution {
public:
    const int _MAX = -1073741824;
    void div(int &dividend, int divisor, int &cnt, int depth) {
        if(dividend > divisor)
            return;
        if(divisor > _MAX)
            div(dividend, divisor + divisor, cnt, depth + depth);
        while(dividend <= divisor) {
            dividend -= divisor;
            cnt += depth;
        }
    }
    int divide(int dividend, int divisor) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int cnt = 0;
        bool isminus = false;
        if(dividend < 0) {
            isminus = !isminus;
        } else {
            dividend = -dividend;
        }
        if(divisor < 0) {
            isminus = !isminus;
        } else {
            divisor = -divisor;
        }
        div(dividend, divisor, cnt, 1);
        return isminus?-cnt:cnt;
    }
};