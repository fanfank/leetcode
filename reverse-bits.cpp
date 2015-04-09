//Solution 1: 10ms
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int cnt = 32;
        while (cnt--) {
            res <<= 1;
            res |= n & 0x00000001;
            n >>= 1;
        }
        return res;
    }
};

//Solution 2: 12ms, an interesting solution
//            please refer to: 
//              https://leetcode.com/discuss/29324/c-solution-9ms-without-loop-without-calculation
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        struct bs
        {
            unsigned int _00:1; unsigned int _01:1; unsigned int _02:1; unsigned int _03:1;
            unsigned int _04:1; unsigned int _05:1; unsigned int _06:1; unsigned int _07:1;
            unsigned int _08:1; unsigned int _09:1; unsigned int _10:1; unsigned int _11:1;
            unsigned int _12:1; unsigned int _13:1; unsigned int _14:1; unsigned int _15:1;
            unsigned int _16:1; unsigned int _17:1; unsigned int _18:1; unsigned int _19:1;
            unsigned int _20:1; unsigned int _21:1; unsigned int _22:1; unsigned int _23:1;
            unsigned int _24:1; unsigned int _25:1; unsigned int _26:1; unsigned int _27:1;
            unsigned int _28:1; unsigned int _29:1; unsigned int _30:1; unsigned int _31:1;
        } *b = (bs*)&n, 
        c = 
        {
              b->_31, b->_30, b->_29, b->_28
            , b->_27, b->_26, b->_25, b->_24
            , b->_23, b->_22, b->_21, b->_20
            , b->_19, b->_18, b->_17, b->_16
            , b->_15, b->_14, b->_13, b->_12
            , b->_11, b->_10, b->_09, b->_08
            , b->_07, b->_06, b->_05, b->_04
            , b->_03, b->_02, b->_01, b->_00
        };

        return *(unsigned int *)&c;
    }
};
