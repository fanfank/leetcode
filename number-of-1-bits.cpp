//Solution 1: 
//           time: O(n)
//           16ms
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        int cnt = 32;
        while (cnt--) {
            res += (0x00000001 & n);
            n >>= 1;
        }
        return res;
    }
};

//Solution 2:
//           time: O(m), m is num of 1s
//           10ms
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            res += 1;
            n &= (n - 1);
        }
        return res;
    }
};
