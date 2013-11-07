class Solution {
public:
    double doPow(double x, long long coe) {
        if(coe == 0)
            return 1;
        long long cnt = 1;
        double tmp = x;
        --coe;
        while(cnt <= coe) {
            x *= x;
            coe -= cnt;
            cnt *= 2;
        }
        return x * pow(tmp, coe);
    }
    double pow(double x, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        long long coe = n;
        if(coe < 0) {
            x = 1.0 / x;
            coe *= -1;
        }
        return doPow(x, coe);
    }
};