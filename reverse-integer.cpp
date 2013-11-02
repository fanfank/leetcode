class Solution {
public:
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ans = 0;
        bool isMinus = false;
        if(x < 0) {
            isMinus = true;
            x = -x;
        }
        while(x) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans * (isMinus?-1:1);
    }
};