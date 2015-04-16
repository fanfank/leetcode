//Solution 1: my solution
//            time: O(1), space: O(1) 
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0x00000000;
        unsigned int bit = 0x80000000;

        while (bit != 0) {
            if ((bit & m) != 0 && (bit & n) != 0) {
                res |= bit;
            } else if ((bit & m) == 0 && (bit & n) == 0) {
                //do nothing
            } else {
                break;
            }
            bit >>= 1;
        }

        return res;
    }
};

//Solution 2: simplified solution
//            refer to: 
//              https://leetcode.com/discuss/32053/accepted-c-solution-with-simple-explanation
int rangeBitwiseAnd(int m, int n) {
    int c=0;
    while(m!=n){
        m>>=1;
        n>>=1;
        ++c;
    }
    return n<<c;
}
